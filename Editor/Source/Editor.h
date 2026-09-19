#pragma once
#include "Commands/CommandManager.h"
#include "EditorMainWindow.h"
#include <memory>

class CEditor
{
public:
    CEditor(const CEditor&) = delete;
    CEditor& operator=(const CEditor&) = delete;

    CEditor(CEditor&&) = delete;
    CEditor& operator=(CEditor&&) = delete;

    static CEditor& Get()
    {
        static CEditor editor;
        return editor;
    }

    class CCommandManager* GetCommandManager() const
    {
        return command_manager.get();
    }

    bool Initialize(Hades::CEngineLoop* in_engine_loop);
    void Shutdown();

    void RegisterMenuBarCommands(class QMainWindow* window);

private:
    CEditor() = default;
    ~CEditor() = default;

    std::unique_ptr<CEditorMainWindow> editor_main_window;
    std::unique_ptr<CCommandManager> command_manager;
};
