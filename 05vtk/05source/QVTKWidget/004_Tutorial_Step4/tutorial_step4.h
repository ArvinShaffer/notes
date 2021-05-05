#ifndef TUTORIAL_STEP4_H
#define TUTORIAL_STEP4_H

#include <QWidget>
#include <vtkActor.h>
#include <vtkCamera.h>
#include <vtkConeSource.h>
#include <vtkNamedColors.h>
#include <vtkNew.h>
#include <vtkPolyDataMapper.h>
#include <vtkProperty.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkGenericOpenGLRenderWindow.h>

QT_BEGIN_NAMESPACE
namespace Ui { class Tutorial_Step4; }
QT_END_NAMESPACE

class Tutorial_Step4 : public QWidget
{
    Q_OBJECT

public:
    Tutorial_Step4(QWidget *parent = nullptr);
    ~Tutorial_Step4();

private:
    Ui::Tutorial_Step4 *ui;
};
#endif // TUTORIAL_STEP4_H
