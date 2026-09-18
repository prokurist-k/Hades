#include "Editor.h"
#include "EditorMainWindow.h"
#include <memory>

bool CEditor::Initialize(Hades::CEngineLoop* in_engine_loop)
{
    editor_main_window = std::make_unique<CEditorMainWindow>(in_engine_loop);
    editor_main_window->show();

    return true;
}
