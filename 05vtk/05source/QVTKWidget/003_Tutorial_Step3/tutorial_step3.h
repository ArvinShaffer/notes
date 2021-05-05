#ifndef TUTORIAL_STEP3_H
#define TUTORIAL_STEP3_H

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
namespace Ui { class Tutorial_Step3; }
QT_END_NAMESPACE

class Tutorial_Step3 : public QWidget
{
    Q_OBJECT

public:
    Tutorial_Step3(QWidget *parent = nullptr);
    ~Tutorial_Step3();

private:
    Ui::Tutorial_Step3 *ui;
};
#endif // TUTORIAL_STEP3_H
