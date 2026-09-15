#include "ViewportWidget.h"
#include <GL/gl.h>
#include <qopenglwidget.h>
#include <qwidget.h>

CViewportWidget::CViewportWidget(QWidget* parent)
    : QOpenGLWidget(parent)
{
}

void CViewportWidget::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(0.0f, 0.4f, 0.0f, 1.0f);
}

void CViewportWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);
}

void CViewportWidget::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
}
