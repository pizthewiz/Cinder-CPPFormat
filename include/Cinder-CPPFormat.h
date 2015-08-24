//
//  Cinder-CPPFormat.h
//  Cinder-CPPFormat
//
//  Created by Jean-Pierre Mouilleseaux on 14 Aug 2015.
//  Copyright 2015 Chorded Constructions. All rights reserved.
//

#pragma once

#include "format.h"

namespace Cinder { namespace Format {

// hoist out of format.h into Cinder::Format as fmt will define a Color type conflicting with ci::Color
FMT_VARIADIC(std::string, format, fmt::StringRef)
FMT_VARIADIC_W(std::wstring, format, fmt::WStringRef)
FMT_VARIADIC(void, print, fmt::StringRef)
FMT_VARIADIC(void, print, std::FILE *, fmt::StringRef)
FMT_VARIADIC(void, print, std::ostream &, fmt::StringRef)
FMT_VARIADIC(void, print_colored, fmt::Color, fmt::StringRef)
FMT_VARIADIC(std::string, sprintf, fmt::StringRef)
FMT_VARIADIC(int, printf, fmt::StringRef)
FMT_VARIADIC(int, fprintf, std::FILE *, fmt::StringRef)

}}
