#include "Commands/CommandManager.h"
#include "Editor.h"
#include "EditorMainWindow.h"
#include "Source/Core/Logging/Log.h"
#include "qaction.h"
#include <memory>
#include <qmainwindow.h>

bool CEditor::Initialize(Hades::CEngineLoop* in_engine_loop)
{
    command_manager = std::make_unique<CCommandManager>();

    editor_main_window = std::make_unique<CEditorMainWindow>(in_engine_loop);
    editor_main_window->show();

    return true;
}

void CEditor::Shutdown()
{
    command_manager.reset();
    editor_main_window.reset();
}

void CEditor::RegisterMenuBarCommands(QMainWindow* window)
{
    QAction* action_new = new QAction("New Level", window);
    action_new->setShortcut(QKeySequence("Ctrl+N"));
    QObject::connect(action_new, &QAction::triggered, [action_new]()
        { HADES_LOG(Log, "Action triggered: %s", action_new->text().toStdString().c_str()) });
    command_manager->RegisterCommand("file.new", action_new);

    QAction* action_open = new QAction("Open...", window);
    action_open->setShortcut(QKeySequence("Ctrl+O"));
    QObject::connect(action_open, &QAction::triggered, [action_open]()
        { HADES_LOG(Log, "Action triggered: %s", action_open->text().toStdString().c_str()) });
    command_manager->RegisterCommand("file.open", action_open);

    QAction* action_save = new QAction("Save", window);
    action_save->setShortcut(QKeySequence("Ctrl+S"));
    QObject::connect(action_save, &QAction::triggered, [action_save]()
        { HADES_LOG(Log, "Action triggered: %s", action_save->text().toStdString().c_str()) });
    command_manager->RegisterCommand("file.save", action_save);

    QAction* action_exit = new QAction("Exit", window);
    action_exit->setShortcut(QKeySequence("Ctrl+Q"));
    QObject::connect(action_exit, &QAction::triggered, window, &QMainWindow::close);
    command_manager->RegisterCommand("file.exit", action_exit);
}
