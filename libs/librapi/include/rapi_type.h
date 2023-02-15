#pragma once

#include <cstdint>

namespace rapi
{
    enum class Type : uint8_t
    {
        Bool      = 0,
        Char      = 1,
        UInt8     = 2,
        Int16     = 3,
        UInt16    = 4,
        Int32     = 5,
        UInt32    = 6,
        Float     = 7,
        Double    = 8,
        UniqueID  = 9,
        String    = 10,
        List      = 11,
        Table     = 12,

        Nil       = 255
    };

    static constexpr bool type_is_signed_int(Type t)
    {
        return t == Type::Bool
            || t == Type::Int16
            || t == Type::Int32;
    }

    static constexpr bool type_is_unsigned_int(Type t)
    {
        return t == Type::UInt8
            || t == Type::UInt16
            || t == Type::UInt32;
    }

    static constexpr bool type_is_floating_point(Type t)
    {
        return t == Type::Float
            || t == Type::Double;
    }
}
