#pragma once
#include "EditorMainWindow.h"

class CEditor
{
public:
    bool Initialize();

private:
    bool InitializeEngine();
    std::unique_ptr<CEditorMainWindow> editor_main_window;
};
