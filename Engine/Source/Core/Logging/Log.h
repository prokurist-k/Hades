#pragma once

#include <memory>
#include <vector>

namespace Hades
{
enum class ELogLevel
{
    Fatal = 0,
    Error = 1,
    Warning = 2,
    Log = 3,
};

namespace LogColors
{
    constexpr const char* red = "\x1B[31m";
    constexpr const char* yellow = "\x1B[33m";
    constexpr const char* white = "\x1B[0m";

    constexpr const char* GetLogColor(const ELogLevel level)
    {
        switch (level)
        {
        case ELogLevel::Log:
            return LogColors::white;
        case ELogLevel::Warning:
            return LogColors::yellow;
        case ELogLevel::Fatal:
        case ELogLevel::Error:
            return LogColors::red;
        default:
            return LogColors::white;
        }
    }
}
const char* LogLevelToString(const ELogLevel log_level);

class CLogger
{
public:
    static CLogger& Get();
    void BasicLog(const ELogLevel level, const char* format, ...);

    void RegisterSink(std::unique_ptr<class ILogSink> new_sink);

private:
    std::vector<std::unique_ptr<class ILogSink>> sinks;
};

#define HADES_LOG(level, format, ...) \
    Hades::CLogger::Get().BasicLog(Hades::ELogLevel::level, format, ##__VA_ARGS__);

}
