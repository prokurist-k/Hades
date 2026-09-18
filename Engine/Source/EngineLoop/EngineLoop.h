#pragma once

#include "Source/Engine/Engine.h"
#include <memory>
namespace Hades
{

struct SEngineLoopParams
{
    bool is_editor = false;
    bool is_embedded = false;
};

class CEngineLoop
{
public:
    bool Initialize(const SEngineLoopParams& params);
    void Shutdown();
    void Run();

    void Tick();

private:
    SEngineLoopParams current_params;
    std::unique_ptr<CEngine> engine;

    bool is_running = false;
};
}
