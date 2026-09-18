#include "Timer.h"
#include <chrono>

namespace Hades
{
CTimer::CTimer()
    : current_game_time(0.0)
    , current_editor_time(0.0)
{
    last_frame_time = std::chrono::high_resolution_clock::now();
}

void CTimer::UpdateOnFrameStart()
{
    auto current_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> elapsed = current_time - last_frame_time;

    unscaled_delta_seconds = elapsed.count();
    if (unscaled_delta_seconds > 0.1f)
    {
        unscaled_delta_seconds = 0.1f;
    }

    delta_seconds = unscaled_delta_seconds * time_scale;

    current_game_time += delta_seconds;
    current_editor_time += unscaled_delta_seconds;

    last_frame_time = current_time;
}
}
