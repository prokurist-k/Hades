#include "Editor.h"
#include "Source/Core/Logging/Log.h"
#include "Source/EngineLoop/EngineLoop.h"
#include <QApplication>
#include <QMainWindow>
#include <qcoreapplication.h>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    Hades::SEngineLoopParams params;
    params.is_editor = true;
    params.is_embedded = true;

    Hades::CEngineLoop engine_loop;
    if (!engine_loop.Initialize(params))
    {
        return -1;
    }
    HADES_LOG(Log, "Editor Engine Loop initialized")

    CEditor editor;
    if (!editor.Initialize(&engine_loop))
    {
        engine_loop.Shutdown();
        return 1;
    }
    HADES_LOG(Log, "Editor initialized")

    int exit_code = app.exec();
    engine_loop.Shutdown();
    return exit_code;
}
