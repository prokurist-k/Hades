#include "EditorMainWindow.h"
#include "Viewport/ViewportWidget.h"
#include <qmainwindow.h>
#include <qmenu.h>
#include <qmenubar.h>
#include <qobjectdefs.h>
#include <qtimer.h>
#include <qwidget.h>

void SMenuBar::Initalize(QMainWindow* main_window)
{
    menu_bar = new QMenuBar(main_window);
    main_window->setMenuBar(menu_bar);

    menu_bar_file = new QMenu("&File");
    menu_bar_file->addAction("New");
    menu_bar_file->addAction("Open");
    menu_bar_file->addAction("Save");
    menu_bar_file->addSeparator();
    menu_bar_file->addAction("Exit");

    menu_bar->addMenu(menu_bar_file);
}

CEditorMainWindow::CEditorMainWindow(Hades::CEngineLoop* in_engine_loop, QWidget* parent)
    : QMainWindow(parent)
    , engine_loop(in_engine_loop)
{
    setWindowTitle("Hades Editor");
    resize(1280, 720);

    viewport = new CViewportWidget(this);
    setCentralWidget(viewport);

    menu_bar.Initalize(this);

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
