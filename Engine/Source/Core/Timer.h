#pragma once

#include <chrono>
namespace Hades
{
class CTimer
{
public:
    CTimer();

    float GetDeltaSeconds() const
    {
        return delta_seconds;
    }

    float GetUnscaledDeltaSeconds() const
    {
        return unscaled_delta_seconds;
    }

    double GetGameTimeSeconds() const
    {
        return current_game_time;
    }

    double GetGameTimeMilliseconds() const
    {
        return current_game_time * 1000.0f;
    }

    double GetEditorTime() const
    {
        return current_editor_time;
    }

    double GetEditorTimeMilliseconds() const
    {
        return current_editor_time * 1000.0f;
    }

    void UpdateOnFrameStart();

private:
    float delta_seconds;
    float unscaled_delta_seconds;

    double current_game_time;
    double current_editor_time;

    std::chrono::high_resolution_clock::time_point last_frame_time;

    float time_scale = 1.0f;
};
}
