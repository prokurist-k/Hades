#include "EditorMainWindow.h"
#include <qmainwindow.h>
#include <qwidget.h>

CEditorMainWindow::CEditorMainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    setWindowTitle("Hades Editor");
    resize(1280, 720);
}
