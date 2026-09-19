#include "Commands/CommandManager.h"
#include "Editor.h"
#include "EditorMainWindow.h"
#include "Source/Core/Logging/Log.h"
#include "Viewport/ViewportWidget.h"
#include <qaction.h>
#include <qmainwindow.h>
#include <qmenu.h>
#include <qmenubar.h>
#include <qobject.h>
#include <qobjectdefs.h>
#include <qtimer.h>
#include <qwidget.h>

CMenu::CMenu(const QString& title, QWidget* parent)
    : QMenu(title, parent)
{
}

QAction* CMenu::AddCommand(const std::string& name)
{
    QAction* action = CEditor::Get().GetCommandManager()->GetCommand(name);
    if (action)
    {
        addAction(action);
        return action;
    }

    HADES_LOG(Error, "Unknown command added: %s", name.c_str())
    return nullptr;
}

void SMenuBar::Initalize(QMainWindow* main_window)
{
    menu_bar = new QMenuBar(main_window);
    main_window->setMenuBar(menu_bar);

    menu_bar_file = new CMenu("&File", menu_bar);
    menu_bar_file->AddCommand("file.new");
    menu_bar_file->AddCommand("file.open");
    menu_bar_file->AddCommand("file.save");
    menu_bar_file->addSeparator();
    menu_bar_file->AddCommand("file.exit");

    menu_bar->addMenu(menu_bar_file);
}

CEditorMainWindow::CEditorMainWindow(Hades::CEngineLoop* in_engine_loop, QWidget* parent)
    : QMainWindow(parent)
    , engine_loop(in_engine_loop)
{
    setWindowTitle("Hades Editor");
    resize(1280, 720);

    CEditor::Get().RegisterMenuBarCommands(this);

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
