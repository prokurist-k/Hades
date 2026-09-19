#include "CommandManager.h"
#include <qaction.h>

void CCommandManager::RegisterCommand(const std::string& name, QAction* action)
{
    commands[name] = action;
}

QAction* CCommandManager::GetCommand(const std::string& name)
{
    auto it = commands.find(name);
    if (it != commands.end())
    {
        return it->second;
    }
    return nullptr;
}
