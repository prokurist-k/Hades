#include "../PlatformUtils.h"

#include <limits.h>
#include <unistd.h>
namespace Hades
{
std::string CPlatform::GetExecutablePath()
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
}
