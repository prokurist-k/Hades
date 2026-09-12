#include "Log.h"
#include "Sink.h"
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstring>

namespace Hades
{
const char* LogLevelToString(const ELogLevel log_level)
{
    switch (log_level)
    {
    case ELogLevel::Fatal:
        return "Fatal";
    case ELogLevel::Error:
        return "Error";
    case ELogLevel::Warning:
        return "Warning";
    case ELogLevel::Log:
        return "Log";
    }
    return "Unknown LogLevel";
}

CLogger& CLogger::Get()
{
    static CLogger logger;
    return logger;
}

void CLogger::RegisterSink(std::unique_ptr<ILogSink> new_sink)
{
    if (new_sink->IsValid())
    {
        sinks.emplace_back(std::move(new_sink));
    }
}

void CLogger::BasicLog(const ELogLevel level, const char* format, ...)
{
    const size_t size = 1024;
    char buffer[size];

    va_list args;
    va_start(args, format);
    vsnprintf(buffer, size, format, args);
    va_end(args);

    for (const auto& s : sinks)
    {
        s->Log(level, buffer);
    }
}
}
