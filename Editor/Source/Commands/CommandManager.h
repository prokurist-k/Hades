#pragma once

#include <string>
#include <unordered_map>

class CCommandManager
{
public:
    void RegisterCommand(const std::string& name, class QAction* action);
    QAction* GetCommand(const std::string& name);

private:
    std::unordered_map<std::string, QAction*> commands;
};
