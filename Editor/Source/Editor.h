#pragma once
#include "EditorMainWindow.h"

class CEditor
{
public:
    bool Initialize(Hades::CEngineLoop* in_engine_loop);

private:
    std::unique_ptr<CEditorMainWindow> editor_main_window;
};
