
# Cinder-CPPFormat
Small, safe and fast formatting library [cppformat](https://github.com/cppformat/cppformat) packaged into a CinderBlock.

### USAGE
```C++
// Arguments can be accessed by position and arguments' indices can be repeated:
std::string s = fmt::format("{0}{1}{0}", "abra", "cad");
// s == "abracadabra"

// C++ Format can be used as a safe portable replacement for itoa:
fmt::MemoryWriter w;
w << 42;           // replaces itoa(42, buffer, 10)
w << fmt::hex(42); // replaces itoa(42, buffer, 16)

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
```

### WHY NOT BOOST?
Use of the Boost library is [being deprecated within Cinder](https://forum.libcinder.org/topic/transitioning-to-cinder-0-9-0), CinderBlock authors are encouraged to not rely on it and `Boost Format` quite a bit slower at compile and run time - see the [cppformat README](https://github.com/cppformat/cppformat#boost-format-library) for more details.

### GREETZ
- [Victor Zverovich](https://github.com/vitaut) and his [cppformat](https://github.com/cppformat/cppformat) library
