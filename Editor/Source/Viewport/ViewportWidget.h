#pragma once

#include <qopenglfunctions.h>
#include <qopenglwidget.h>
#include <qtmetamacros.h>

class CViewportWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    CViewportWidget(class QWidget* parent = nullptr);

protected:
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int w, int h) override;
};
