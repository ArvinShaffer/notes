#include "tutorial_step5.h"

#include <QApplication>
#include <qsurfaceformat.h>
#include <QVTKOpenGLWidget.h>

int main(int argc, char *argv[])
{
    QSurfaceFormat::setDefaultFormat(QVTKOpenGLWidget::defaultFormat());
    QApplication a(argc, argv);
    Tutorial_Step5 w;
    w.show();
    return a.exec();
}
