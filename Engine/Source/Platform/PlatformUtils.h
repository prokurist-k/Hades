#pragma once

#include "Source/Platform/Keyboard.h"
#include <cstdint>
#include <string>

namespace Hades
{

constexpr uint64_t NANOSECONDS_PER_SECOND = 1'000'000'000ULL;

class CPlatformUtils
{
public:
    static void InitializeKeyTable();
    static std::string GetExecutablePath();
    static uint64_t GetTicks();
    static EKey TranslateKeyCode(uint32_t native_keycode);

private:
    static std::array<EKey, 256> key_table;
};

}
