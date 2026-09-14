#include "Editor.h"
#include "EditorMainWindow.h"
#include "Source/Utility/Paths.h"
#include <memory>

bool CEditor::Initialize()
{
    if (!InitializeEngine())
    {
        return false;
    }

    editor_main_window = std::make_unique<CEditorMainWindow>();
    editor_main_window->show();

    return true;
}

bool CEditor::InitializeEngine()
{
    if (!Hades::CPaths::Initialize())
    {
        return false;
    }

    return true;
}
