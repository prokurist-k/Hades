#include "../../Utility/Paths.h"
#include "Sink.h"
#include "Source/Core/Logging/Log.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <filesystem>

namespace Hades
{

bool CConsoleSink::IsValid() const
{
    return true;
}

void CConsoleSink::Log(const ELogLevel level, const char* message)
{
    const char* log_level_string = LogLevelToString(level);
    size_t final_log_message_size = 1024;
    char final_log_message[final_log_message_size];
    snprintf(final_log_message, final_log_message_size, "[%s] %s\n", log_level_string, message);
    printf("%s%s%s", LogColors::GetLogColor(level), final_log_message, LogColors::white);
}

CFileSink::CFileSink()
{
    std::filesystem::create_directories(CPaths::GameLogDir());
    std::string log_file = (std::filesystem::path(CPaths::GameLogDir()) / "log.txt").string();
    file = fopen(log_file.c_str(), "a");
}

CFileSink::~CFileSink()
{
    if (file != nullptr)
    {
        fclose(file);
    }
    file = nullptr;
}

bool CFileSink::IsValid() const
{
    return file != NULL;
}

void CFileSink::Log(const ELogLevel level, const char* message)
{
    if (file == NULL)
    {
        return;
    }

    const char* log_level_string = LogLevelToString(level);
    size_t final_log_message_size = 1024;
    char final_log_message[final_log_message_size];
    snprintf(final_log_message, final_log_message_size, "[%s] %s\n", log_level_string, message);
    fprintf(file, "%s", final_log_message);
    fflush(file);
}
}
