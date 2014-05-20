#ifndef MAGIC_INTERPRETER_T_HPP
#define MAGIC_INTERPRETER_T_HPP

#include "../common/utils2.hpp"

enum class SPELLARG : uint8_t
{
    NONE,
    PC,
    STRING,
};

enum class TYPE : uint8_t
{
    UNDEF,
    INT,
    DIR,
    STRING,
    ENTITY,
    LOCATION,
    AREA,
    SPELL,
    INVOCATION,
    FAIL = 127,

    NEGATIVE_1 = 255,
};

// Note: there is also a typedef by this name in <dirent.h>
// but we should be fine since we never include it.
// (in the long term we should still rename this though)
enum class DIR : uint8_t
{
    S   = 0,
    SW  = 1,
    W   = 2,
    NW  = 3,
    N   = 4,
    NE  = 5,
    E   = 6,
    SE  = 7,

    COUNT,
};

constexpr
earray<int, DIR, DIR::COUNT> dirx //=
{{
    0, -1, -1, -1, 0, 1, 1, 1,
}}, diry //=
{{
    1, 1, 0, -1, -1, -1, 0, 1,
}};

constexpr
bool dir_is_diagonal(DIR d)
{
    return static_cast<uint8_t>(d) & 1;
}

enum class AREA : uint8_t
{
    LOCATION,
    UNION,
    RECT,
    BAR,
};

enum class EXPR : uint8_t
{
    VAL,
    LOCATION,
    AREA,
    FUNAPP,
    ID,
    SPELLFIELD,
};

// temporary rename to avoid collision with enum value
// in magic-interpreter-parser
enum class EFFECT : uint8_t
{
    SKIP,
    ABORT,
    ASSIGN,
    FOREACH,
    FOR,
    IF,
    SLEEP,
    SCRIPT,
    BREAK,
    OP,
    END,
    CALL,
};

enum class FOREACH_FILTER : uint8_t
{
    MOB,
    PC,
    ENTITY,
    TARGET,
    SPELL,
    NPC,
};

enum class SPELLGUARD : uint8_t
{
    CONDITION,
    COMPONENTS,
    CATALYSTS,
    CHOICE,
    MANA,
    CASTTIME,
    EFFECT,
};

namespace e
{
enum class SPELL_FLAG : uint8_t
{
    ZERO        = 0,

    // spell associated not with caster but with place
    LOCAL       = 1 << 0,
    // spell invocation never uttered
    SILENT      = 1 << 1,
    // `magic word' only:  don't require spellcasting ability
    NONMAGIC    = 1 << 2,
};
ENUM_BITWISE_OPERATORS(SPELL_FLAG)
}
using e::SPELL_FLAG;

enum class CONT_STACK : uint8_t
{
    FOREACH,
    FOR,
    PROC,
};

namespace e
{
enum class INVOCATION_FLAG : uint8_t
{
    ZERO        = 0,

    // Bound directly to the caster (i.e., ignore its location)
    BOUND       = 1 << 0,
    // Used `abort' to terminate
    ABORTED     = 1 << 1,
    // On magical attacks: if we run out of steam, stop attacking altogether
    STOPATTACK  = 1 << 2,
};
ENUM_BITWISE_OPERATORS(INVOCATION_FLAG)
}
using e::INVOCATION_FLAG;

#endif // MAGIC_INTERPRETER_T_HPP
