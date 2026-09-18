#include "../PlatformUtils.h"

#include <cstdint>
#include <ctime>
#include <limits.h>
#include <unistd.h>
namespace Hades
{
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

}
