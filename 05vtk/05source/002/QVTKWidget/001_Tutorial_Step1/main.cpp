#include "tutorialstep1.h"

#include <QApplication>
#include <qsurfaceformat.h>
#include <QVTKOpenGLWidget.h>

int main(int argc, char *argv[])
{
    QSurfaceFormat::setDefaultFormat(QVTKOpenGLWidget::defaultFormat());
    QApplication a(argc, argv);
    TutorialStep1 w;
    w.show();
    return a.exec();
}
