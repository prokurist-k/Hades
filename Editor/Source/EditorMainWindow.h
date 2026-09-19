#pragma once
#include "Source/EngineLoop/EngineLoop.h"
#include <qmainwindow.h>
#include <qmenu.h>
#include <qobjectdefs.h>

class CMenu : public QMenu
{
public:
    CMenu(const QString& title, class QWidget* parent = nullptr);
    class QAction* AddCommand(const std::string& name);
};

struct SMenuBar
{
    void Initalize(QMainWindow* main_window);

    class QMenuBar* menu_bar;
    class CMenu* menu_bar_file;
};

class CEditorMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    CEditorMainWindow(Hades::CEngineLoop* in_engine_loop, class QWidget* parent = nullptr);
    virtual ~CEditorMainWindow();

private slots:
    void OnEngineTick();

private:
    class CViewportWidget* viewport = nullptr;
    Hades::CEngineLoop* engine_loop;
    QTimer* tick_timer;
    SMenuBar menu_bar;
};
