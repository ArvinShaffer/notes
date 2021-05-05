#ifndef TUTORIAL_STEP6_H
#define TUTORIAL_STEP6_H

#include <QWidget>
#include <vtkActor.h>
#include <vtkBoxWidget.h>
#include <vtkCamera.h>
#include <vtkCommand.h>
#include <vtkConeSource.h>
#include <vtkInteractorStyleTrackballCamera.h>
#include <vtkNamedColors.h>
#include <vtkNew.h>
#include <vtkPolyDataMapper.h>
#include <vtkProperty.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include <vtkTransform.h>
#include <vtk-8.1/vtkAutoInit.h>
VTK_MODULE_INIT(vtkRenderingOpenGL2); // VTK was built with vtkRenderingOpenGL2
VTK_MODULE_INIT(vtkInteractionStyle);

namespace {
class vtkMyCallback : public vtkCommand
{
public:
  static vtkMyCallback* New()
  {
    return new vtkMyCallback;
  }
  void Execute(vtkObject* caller, unsigned long, void*) override
  {
    vtkNew<vtkTransform> t;
    auto widget = reinterpret_cast<vtkBoxWidget*>(caller);
    widget->GetTransform(t);
    widget->GetProp3D()->SetUserTransform(t);
  }
};
}


QT_BEGIN_NAMESPACE
namespace Ui { class Tutorial_Step6; }
QT_END_NAMESPACE

class Tutorial_Step6 : public QWidget
{
    Q_OBJECT

public:
    Tutorial_Step6(QWidget *parent = nullptr);
    ~Tutorial_Step6();

private:
    Ui::Tutorial_Step6 *ui;
};
#endif // TUTORIAL_STEP6_H
