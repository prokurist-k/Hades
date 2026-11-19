#include "../PlatformUtils.h"
#include "Source/Core/Logging/Log.h"
#include "Source/Platform/Keyboard.h"
#include <array>
#include <cstdint>
#include <ctime>
#include <limits.h>
#include <unistd.h>

namespace Hades
{

std::array<EKey, 256> CPlatformUtils::key_table;

void CPlatformUtils::InitializeKeyTable()
{
    HADES_LOG(Log, "Initialize key table");
    key_table.fill(EKey::Unknown);

    key_table[9] = EKey::Escape;
    key_table[10] = EKey::Key_1;
    key_table[11] = EKey::Key_2;
    key_table[12] = EKey::Key_3;
    key_table[13] = EKey::Key_4;
    key_table[14] = EKey::Key_5;
    key_table[15] = EKey::Key_6;
    key_table[16] = EKey::Key_7;
    key_table[17] = EKey::Key_8;
    key_table[18] = EKey::Key_9;
    key_table[19] = EKey::Key_0;
    key_table[20] = EKey::Minus;
    key_table[21] = EKey::Equal;
    key_table[22] = EKey::Backspace;
    key_table[23] = EKey::Tab;
    key_table[24] = EKey::Q;
    key_table[25] = EKey::W;
    key_table[26] = EKey::E;
    key_table[27] = EKey::R;
    key_table[28] = EKey::T;
    key_table[29] = EKey::Y;
    key_table[30] = EKey::U;
    key_table[31] = EKey::I;
    key_table[32] = EKey::O;
    key_table[33] = EKey::P;
    key_table[34] = EKey::Bracketleft;
    key_table[35] = EKey::Bracketright;
    key_table[36] = EKey::Return;
    key_table[37] = EKey::Unknown;
    key_table[38] = EKey::A;
    key_table[39] = EKey::S;
    key_table[40] = EKey::D;
    key_table[41] = EKey::F;
    key_table[42] = EKey::G;
    key_table[43] = EKey::H;
    key_table[44] = EKey::J;
    key_table[45] = EKey::K;
    key_table[46] = EKey::L;
    key_table[47] = EKey::Semicolon;
    key_table[48] = EKey::Dead_Acute;
    key_table[49] = EKey::Dead_Grave;
    key_table[50] = EKey::Shift_L;
    key_table[51] = EKey::Backslash;
    key_table[52] = EKey::Z;
    key_table[53] = EKey::X;
    key_table[54] = EKey::C;
    key_table[55] = EKey::V;
    key_table[56] = EKey::B;
    key_table[57] = EKey::N;
    key_table[58] = EKey::M;
    key_table[59] = EKey::Comma;
    key_table[60] = EKey::Period;
    key_table[61] = EKey::Slash;
    key_table[62] = EKey::Shift_R;
    key_table[63] = EKey::KP_Multiply;
    key_table[64] = EKey::Alt_L;
    key_table[65] = EKey::Space;
    key_table[66] = EKey::Caps_Lock;
    key_table[67] = EKey::F1;
    key_table[68] = EKey::F2;
    key_table[69] = EKey::F3;
    key_table[70] = EKey::F4;
    key_table[71] = EKey::F5;
    key_table[72] = EKey::F6;
    key_table[73] = EKey::F7;
    key_table[74] = EKey::F8;
    key_table[75] = EKey::F9;
    key_table[76] = EKey::F10;
}

std::string CPlatformUtils::GetExecutablePath()
{
    char buffer[PATH_MAX];
    ssize_t len = readlink("/proc/self/exe", buffer, sizeof(buffer) - 1);
    if (len == -1)
    {
        return "";
    }
    buffer[len] = '\0';
    return std::string(buffer);
}

uint64_t CPlatformUtils::GetTicks()
{
    struct timespec tp;
    clock_gettime(CLOCK_MONOTONIC, &tp);
    return tp.tv_sec * NANOSECONDS_PER_SECOND + tp.tv_nsec;
}

EKey CPlatformUtils::TranslateKeyCode(uint32_t native_key_code)
{
    if (native_key_code >= 256)
    {
        return EKey::Unknown;
    }

    return key_table[native_key_code];
}

}
