#pragma once
#include <cstdint>
#include <string>

namespace Hades
{

enum class EKey : uint8_t
{
    Unknown = 0,
    Escape,
    Key_0,
    Key_1,
    Key_2,
    Key_3,
    Key_4,
    Key_5,
    Key_6,
    Key_7,
    Key_8,
    Key_9,

    Minus,
    Equal,
    Backspace,
    Tab,

    Bracketleft,
    Bracketright,
    Return,

    Semicolon,
    Dead_Acute,
    Dead_Grave,
    Shift_L,
    Backslash,

    Comma,
    Period,
    Slash,
    Shift_R,
    KP_Multiply,

    Alt_L,

    Caps_Lock,

    F1,
    F2,
    F3,
    F4,
    F5,
    F6,
    F7,
    F8,
    F9,
    F10,

    A,
    B,
    C,
    D,
    E,
    F,
    G,
    H,
    I,
    J,
    K,
    L,
    M,
    N,
    O,
    P,
    Q,
    R,
    S,
    T,
    U,
    V,
    W,
    X,
    Y,
    Z,
    Space,
    Count
};

std::string KeyToString(EKey key);
}
