#pragma once

#include "PlatformEvents.h"
#include <vector>

namespace Hades
{
class IWindow
{
public:
    virtual ~IWindow() = default;

    virtual bool Initialize() = 0;
    virtual void Shutdown() = 0;

    virtual void Show() = 0;

    virtual void ProcessEvents(std::vector<Event>& events) = 0;
    virtual bool IsOpen() const = 0;
};
}
