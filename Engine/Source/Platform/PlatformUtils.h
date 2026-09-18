#pragma once

#include <cstdint>
#include <string>

namespace Hades
{

constexpr uint64_t NANOSECONDS_PER_SECOND = 1'000'000'000ULL;

class CPlatformUtils
{
public:
    static std::string GetExecutablePath();
    static uint64_t GetTicks();
};

}
