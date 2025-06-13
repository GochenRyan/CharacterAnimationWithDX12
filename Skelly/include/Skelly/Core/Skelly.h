#pragma once
#ifdef SKELLY_EXPORTS
#define SKELLY_API __declspec(dllexport)
#else
#define SKELLY_API __declspec(dllimport)
#endif

#include <cstdint>
#include <cstddef>
#include <cfloat>
#include <climits>
#include <limits>
#include <type_traits>

namespace Skelly 
{
    using UInt8  = uint8_t;
    using UInt16 = uint16_t;
    using UInt32 = uint32_t;
    using UInt64 = uint64_t;

    using Int8   = int8_t;
    using Int16  = int16_t;
    using Int32  = int32_t;
    using Int64  = int64_t;

    using Float32 = float;
    using Float64 = double;

    #if defined(__cpp_char8_t) && __cpp_char8_t >= 201811L
    #include <uchar.h>
    using Char8 = char8_t;
    #else
    using Char8 = unsigned char;
    #endif
    using Char16 = char16_t;
    using Char32 = char32_t;

    using SizeT = std::size_t;
    using PtrDiff = std::ptrdiff_t;

    using IntPtr = std::intptr_t;
    using UIntPtr = std::uintptr_t;

    using Byte = std::byte;

    using Handle = void*;

    using Index = SizeT;
    using Offset = PtrDiff;

    using Timestamp = UInt64;

    using Flags = UInt32;

    namespace Constants 
    {
        constexpr Int8  MinInt8  = std::numeric_limits<Int8>::min();
        constexpr Int16 MinInt16 = std::numeric_limits<Int16>::min();
        constexpr Int32 MinInt32 = std::numeric_limits<Int32>::min();
        constexpr Int64 MinInt64 = std::numeric_limits<Int64>::min();

        constexpr UInt8  MaxUInt8  = std::numeric_limits<UInt8>::max();
        constexpr UInt16 MaxUInt16 = std::numeric_limits<UInt16>::max();
        constexpr UInt32 MaxUInt32 = std::numeric_limits<UInt32>::max();
        constexpr UInt64 MaxUInt64 = std::numeric_limits<UInt64>::max();

        constexpr Float32 EpsilonF32 = FLT_EPSILON;
        constexpr Float64 EpsilonF64 = DBL_EPSILON;
    }
}