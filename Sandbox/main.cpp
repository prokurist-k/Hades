#include "../Engine/Source/Core/Logging/Log.h"
#include "Source/EngineLoop/EngineLoop.h"

int main(int argc, char* argv[])
{
    Hades::SEngineLoopParams params;
    params.is_editor = false;
    params.is_embedded = false;

    Hades::CEngineLoop engine_loop;
    if (!engine_loop.Initialize(params))
    {
        HADES_LOG(Fatal, "Failed to initialize EngineLoop")
        return -1;
    }
    engine_loop.Run();
    engine_loop.Shutdown();

    return 0;
}
