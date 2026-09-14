#include "Editor.h"
#include <QApplication>
#include <QMainWindow>
#include <qcoreapplication.h>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    CEditor editor;
    if (!editor.Initialize())
    {
        return 1;
    }

    return app.exec();
}
