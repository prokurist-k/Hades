#pragma once

#include "../Renderer/Renderer.h"
#include "Source/Core/Timer.h"
#include "Source/Platform/PlatformEvents.h"
#include "Source/Platform/Window.h"
#include <memory>
#include <vector>

namespace Hades
{
class CEngine
{
public:
    bool Initialize();
    void Shutdown();

    void Tick();

    IWindow& GetWindow() const
    {
        return *window;
    }

    const CTimer& GetTimer() const
    {
        return timer;
    }

    std::vector<Event>& GetEvents()
    {
        return events;
    }

private:
    void Update(const float delta_seconds);
    void Render();
    void ProcessEvents();

    CTimer timer;
    std::unique_ptr<IWindow> window;
    std::unique_ptr<IRenderer> renderer;

    std::vector<Event> events;
};
}
