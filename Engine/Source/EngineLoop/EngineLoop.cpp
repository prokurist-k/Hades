#include "EngineLoop.h"
#include "Source/Engine/Engine.h"
#include <memory>

namespace Hades
{
bool CEngineLoop::Initialize(const SEngineLoopParams& params)
{
    current_params = params;
    engine = std::make_unique<CEngine>();
    if (!engine->Initialize())
    {
        return false;
    }

    return is_running = true;
}

void CEngineLoop::Shutdown()
{
    if (engine)
    {
        engine->Shutdown();
    }
}

void CEngineLoop::Run()
{
    if (current_params.is_embedded)
    {
        return;
    }

    while (is_running)
    {
        Tick();
    }
}

void CEngineLoop::Tick()
{
    engine->Tick();
}

}
