
# Cinder-CPPFormat
Small, safe and fast formatting library [C++ Format](https://github.com/cppformat/cppformat) (cppformat) packaged into a CinderBlock.

### USAGE
```C++
// Python-like format string syntax:
std::string s = fmt::format("The answer is {}", 42);
// s == "The answer is 42"

// Arguments can be accessed by position and arguments' indices can be repeated:
std::string s = fmt::format("{0}{1}{0}", "abra", "cad");
// s == "abracadabra"

// printf-like numeric formatting:
std::string s = fmt::format("π {:.2f}", 3.1415926535f);
// s == "π 3.14"

// Errors in format strings are reported via exceptions to prevent buffer overflows:
std::string s = fmt::format("The answer is {0:d}", "forty-two");
// fmt::FormatError, description == "unknown format code 'd' for string"

// An object of any user-defined type for which there is an overloaded std::ostream insertion operator (operator<<) can be formatted
class Date {
    int year_, month_, day_;
public:
    Date(int year, int month, int day) : year_(year), month_(month), day_(day) {}

    friend std::ostream &operator<<(std::ostream &os, const Date &d) {
        return os << d.year_ << '-' << d.month_ << '-' << d.day_;
    }
};

std::string s = fmt::format("The date is {}", Date(2012, 12, 9));
// s == "The date is 2012-12-9"

// C++ Format can be used as a safe portable replacement for itoa:
fmt::MemoryWriter w;
w << 42;           // replaces itoa(42, buffer, 10)
w << fmt::hex(42); // replaces itoa(42, buffer, 16)
```

The `fmt::format` macros have been aliased in the `Cinder::Format` namespace to help avoid potential issues caused by using the `fmt` namespace which defines its own `Color` type. See the [C++ Format documentation](http://cppformat.github.io/1.1.0/index.html) and particularly the [format string syntax](http://cppformat.github.io/1.1.0/syntax.html) for more detail on usage.

### WHAT OF BOOST?
Use of the Boost library is [being deprecated within Cinder](https://forum.libcinder.org/topic/transitioning-to-cinder-0-9-0), CinderBlock authors are encouraged to not rely on it and `Boost Format` is quite a bit slower at compile _and_ run time - see the [C++ Format README](https://github.com/cppformat/cppformat#boost-format-library) for more benchmark details.

### GREETZ
- [Victor Zverovich](https://github.com/vitaut) and his [C++ Format](https://github.com/cppformat/cppformat) library
