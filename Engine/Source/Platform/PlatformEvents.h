#pragma once

#include "Source/Platform/Keyboard.h"
#include <cstdint>
#include <variant>

namespace Hades
{
struct SWindowCloseRequested
{
};

struct SWindowResized
{
    uint32_t width;
    uint32_t height;
};

struct SWindowFocusChanged
{
    bool focused;
};

struct SKeyPressed
{
    EKey key;
    bool repeat;
};

struct SKeyReleased
{
    EKey key;
};

struct SMouseButtonPressed
{
    uint32_t button;
};

struct SMouseButtonReleased
{
    uint32_t button;
};

struct SMouseScrolled
{
    float dx;
    float dy;
};

using Event = std::variant<SWindowCloseRequested, SWindowResized, SWindowFocusChanged, SKeyPressed, SKeyReleased, SMouseButtonPressed, SMouseButtonReleased, SMouseScrolled>;

}
