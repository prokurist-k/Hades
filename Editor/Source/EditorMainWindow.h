#pragma once
#include <qmainwindow.h>

class CEditorMainWindow : public QMainWindow
{
public:
    CEditorMainWindow(class QWidget* parent = nullptr);
    virtual ~CEditorMainWindow();

private:
    class CViewportWidget* viewport = nullptr;
};
