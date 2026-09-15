#include "EditorMainWindow.h"
#include "Viewport/ViewportWidget.h"
#include <qmainwindow.h>
#include <qwidget.h>

CEditorMainWindow::CEditorMainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    setWindowTitle("Hades Editor");
    resize(1280, 720);

    viewport = new CViewportWidget(this);
    setCentralWidget(viewport);
}

CEditorMainWindow::~CEditorMainWindow()
{
    if (viewport != nullptr)
    {
        delete viewport;
        viewport = nullptr;
    }
}
