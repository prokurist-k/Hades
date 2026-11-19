#include "../Platform/Window.h"
#include "EngineLoop.h"
#include "Source/Engine/Engine.h"
#include "Source/Globals.h"
#include <memory>

namespace Hades
{
bool CEngineLoop::Initialize(const SEngineLoopParams& params)
{
    current_params = params;
    engine = std::make_unique<CEngine>();
    if (!engine->Initialize())
    {
        engine.reset();
        current_params.is_editor = false;
        current_params.is_embedded = false;
        return false;
    }

    return true;
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

    engine->GetWindow().Show();

    while (!request_exit)
    {
        Tick();
    }
}

void CEngineLoop::Tick()
{
    engine->Tick();
}

}
