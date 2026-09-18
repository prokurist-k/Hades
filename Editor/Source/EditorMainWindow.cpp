#include "EditorMainWindow.h"
#include "Viewport/ViewportWidget.h"
#include <qmainwindow.h>
#include <qobjectdefs.h>
#include <qtimer.h>
#include <qwidget.h>

CEditorMainWindow::CEditorMainWindow(Hades::CEngineLoop* in_engine_loop, QWidget* parent)
    : QMainWindow(parent)
    , engine_loop(in_engine_loop)
{
    setWindowTitle("Hades Editor");
    resize(1280, 720);

    viewport = new CViewportWidget(this);
    setCentralWidget(viewport);

    tick_timer = new QTimer(this);
    connect(tick_timer, &QTimer::timeout, this, &CEditorMainWindow::OnEngineTick);
    tick_timer->start(16);
}

CEditorMainWindow::~CEditorMainWindow()
{
    if (viewport != nullptr)
    {
        delete viewport;
        viewport = nullptr;
    }
}

void CEditorMainWindow::OnEngineTick()
{
    engine_loop->Tick();
    viewport->update();
}
