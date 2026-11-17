#pragma once

#include "../Renderer/Renderer.h"
#include "Source/Core/Timer.h"
#include "Source/Platform/Window.h"
#include <memory>
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

private:
    void Update(const float delta_seconds);
    void Render();

    CTimer timer;
    std::unique_ptr<IWindow> window;
    std::unique_ptr<IRenderer> renderer;
};
}
