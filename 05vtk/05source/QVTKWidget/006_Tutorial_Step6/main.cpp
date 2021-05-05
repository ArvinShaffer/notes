#include "tutorial_step6.h"

#include <QApplication>
#include <qsurfaceformat.h>
#include <QVTKOpenGLWidget.h>

int main(int argc, char *argv[])
{
    QSurfaceFormat::setDefaultFormat(QVTKOpenGLWidget::defaultFormat());
    QApplication a(argc, argv);
    Tutorial_Step6 w;
    w.show();
    return a.exec();
}
