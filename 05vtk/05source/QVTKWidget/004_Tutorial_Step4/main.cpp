#include "tutorial_step4.h"

#include <QApplication>
#include <qsurfaceformat.h>
#include <QVTKOpenGLWidget.h>


int main(int argc, char *argv[])
{
    QSurfaceFormat::setDefaultFormat(QVTKOpenGLWidget::defaultFormat());
    QApplication a(argc, argv);
    Tutorial_Step4 w;
    w.show();
    return a.exec();
}
