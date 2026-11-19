#include "../Platform/Linux/LinuxWindow.h"
#include "../Renderer/Vulkan/VulkanRenderer.h"
#include "Engine.h"
#include "Source/Core.h"
#include "Source/Core/Logging/Log.h"
#include "Source/Core/Logging/Sink.h"
#include "Source/Globals.h"
#include "Source/Platform/Keyboard.h"
#include "Source/Platform/PlatformUtils.h"
#include "Source/Utility/Paths.h"
#include <memory>

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

    CPlatformUtils::InitializeKeyTable();

    window = std::make_unique<CLinuxWindow>();
    if (!window->Initialize())
    {
        HADES_LOG(Fatal, "Failed to initilaize window")
        window.reset();
        return false;
    }

    renderer = std::make_unique<CVulkanRenderer>();
    if (!renderer->Initialize())
    {
        HADES_LOG(Fatal, "Failed to initilaize renderer")
        renderer.reset();
        return false;
    }

    return true;
}
void CEngine::Shutdown()
{
    HADES_LOG(Log, "Engine shutdown")
    renderer->Shutdown();
    renderer.reset();

    window->Shutdown();
    window.reset();
}

void CEngine::Tick()
{
    timer.UpdateOnFrameStart();

    Update(timer.GetDeltaSeconds());
    Render();
}

void CEngine::Update(const float delta_seconds)
{
    events.clear();
    window->ProcessEvents(events);
    ProcessEvents();
}

void CEngine::Render()
{
}

void CEngine::ProcessEvents()
{
    for (const auto& e : events)
    {
        if (const auto k = std::get_if<SWindowCloseRequested>(&e))
        {
            UNUSED(k)
            request_exit = true;
        }
        else if (const auto k = std::get_if<SKeyPressed>(&e))
        {
            HADES_LOG(Log, "Key %s pressed", KeyToString(k->key).c_str())
        }
        else if (const auto k = std::get_if<SKeyReleased>(&e))
        {
            HADES_LOG(Log, "Key %s released", KeyToString(k->key).c_str())
        }
    }
}

}
