#include "Paths.h"
#include <filesystem>

#include "../Platform/PlatformUtils.h"

namespace Hades
{
std::string CPaths::root_directory;
std::string CPaths::engine_directory;
std::string CPaths::game_directory;

bool CPaths::Initialize()
{
    const std::string executable_path = CPlatform::GetExecutablePath();

    std::filesystem::path current_path = std::filesystem::path(executable_path).parent_path();

    const std::string engine_dir_name = "Engine";
    const std::string game_dir_name = "Sandbox";

    while (current_path.has_parent_path() && current_path.parent_path() != current_path)
    {
        bool engine_dir_found = std::filesystem::is_directory(current_path / engine_dir_name);
        bool game_dir_found = std::filesystem::is_directory(current_path / game_dir_name);

        if (engine_dir_found && game_dir_found)
        {
            root_directory = current_path.string();
            break;
        }

        current_path = current_path.parent_path();
    }

    if (root_directory.empty())
    {
        // HADES_LOG(Fatal, "Could not find engine root directory (expected to find subfolders '%s' and '%s').", engine_dir_name.c_str(), game_dir_name.c_str());
        root_directory = ""; // platform->GetWorkingDirectory(); // Fallback
        return false;
    }

    std::filesystem::path root_path(root_directory);
    root_directory = root_path.lexically_normal().string();

    engine_directory = (std::filesystem::path(root_directory) / engine_dir_name).string();
    game_directory = (std::filesystem::path(root_directory) / game_dir_name).string();

    return true;
}

std::string CPaths::EngineDir()
{
    return engine_directory;
}

std::string CPaths::EngineConfigDir()
{
    const std::string config_folder_name = "Config";
    return (std::filesystem::path(engine_directory) / config_folder_name).string();
}

std::string CPaths::EngineIniPath()
{
    const std::string engine_ini_filename = "Engine.ini";
    return (std::filesystem::path(EngineConfigDir()) / engine_ini_filename).string();
}

std::string CPaths::EngineContentDir()
{
    const std::string content_folder_name = "Content";
    return (std::filesystem::path(engine_directory) / content_folder_name).string();
}

std::string CPaths::GameDir()
{
    return game_directory;
}

std::string CPaths::GameConfigDir()
{
    const std::string config_folder_name = "Config";
    return (std::filesystem::path(game_directory) / config_folder_name).string();
}

std::string CPaths::GameContentDir()
{
    const std::string content_folder_name = "Content";
    return (std::filesystem::path(game_directory) / content_folder_name).string();
}

std::string CPaths::GameSavedDir()
{
    const std::string saved_folder_name = "Saved";
    return (std::filesystem::path(game_directory) / saved_folder_name).string();
}

std::string CPaths::GameLogDir()
{
    const std::string log_folder_name = "Logs";
    return (std::filesystem::path(GameSavedDir()) / log_folder_name).string();
}
}
