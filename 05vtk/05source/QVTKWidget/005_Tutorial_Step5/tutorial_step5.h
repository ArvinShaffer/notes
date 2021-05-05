#ifndef TUTORIAL_STEP5_H
#define TUTORIAL_STEP5_H

#include <QWidget>
#include <vtkActor.h>
#include <vtkCamera.h>
#include <vtkConeSource.h>
#include <vtkInteractorStyleTrackballCamera.h>
#include <vtkNamedColors.h>
#include <vtkNew.h>
#include <vtkPolyDataMapper.h>
#include <vtkProperty.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>

QT_BEGIN_NAMESPACE
namespace Ui { class Tutorial_Step5; }
QT_END_NAMESPACE

class Tutorial_Step5 : public QWidget
{
    Q_OBJECT

public:
    Tutorial_Step5(QWidget *parent = nullptr);
    ~Tutorial_Step5();

private:
    Ui::Tutorial_Step5 *ui;
};
#endif // TUTORIAL_STEP5_H
