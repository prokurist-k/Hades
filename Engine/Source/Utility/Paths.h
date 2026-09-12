#pragma once

#include <string>
namespace Hades
{
class CPaths
{
public:
    static bool Initialize();

    static std::string EngineDir();
    static std::string EngineConfigDir();
    static std::string EngineIniPath();
    static std::string EngineContentDir();

    static std::string GameDir();
    static std::string GameConfigDir();
    static std::string GameContentDir();

    static std::string GameSavedDir();
    static std::string GameLogDir();

private:
    static std::string root_directory;
    static std::string engine_directory;
    static std::string game_directory;
};
}
