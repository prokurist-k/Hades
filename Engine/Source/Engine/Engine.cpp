#include "Engine.h"
#include "Source/Core/Logging/Log.h"
#include "Source/Core/Logging/Sink.h"
#include "Source/Utility/Paths.h"

namespace Hades
{
bool CEngine::Initialize()
{
    if (!CPaths::Initialize())
    {
        return false;
    }

    CLogger::Get().RegisterSink(std::make_unique<CConsoleSink>());
    HADES_LOG(Log, "Console sink registerd")
    CLogger::Get().RegisterSink(std::make_unique<Hades::CFileSink>());
    HADES_LOG(Log, "File sink registerd")

    return true;
}
void CEngine::Shutdown()
{
    HADES_LOG(Log, "Engine shutdown")
}

void CEngine::Tick()
{
    timer.UpdateOnFrameStart();

    Update(timer.GetDeltaSeconds());
    Render();
}

void CEngine::Update(const float delta_seconds)
{
}

void CEngine::Render()
{
}

}
