#pragma once

#include "Source/Core/Timer.h"
namespace Hades
{
class CEngine
{
public:
    bool Initialize();
    void Shutdown();

    void Tick();

    const CTimer& GetTimer() const
    {
        return timer;
    }

private:
    void Update(const float delta_seconds);
    void Render();

    CTimer timer;
};
}
