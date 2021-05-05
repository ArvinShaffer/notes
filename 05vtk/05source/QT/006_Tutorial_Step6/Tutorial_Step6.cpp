#include <vtk-8.1/vtkActor.h>
#include <vtk-8.1/vtkBoxWidget.h>
#include <vtk-8.1/vtkCamera.h>
#include <vtk-8.1/vtkCommand.h>
#include <vtk-8.1/vtkConeSource.h>
#include <vtk-8.1/vtkInteractorStyleTrackballCamera.h>
#include <vtk-8.1/vtkNamedColors.h>
#include <vtk-8.1/vtkNew.h>
#include <vtk-8.1/vtkPolyDataMapper.h>
#include <vtk-8.1/vtkProperty.h>
#include <vtk-8.1/vtkRenderWindow.h>
#include <vtk-8.1/vtkRenderWindowInteractor.h>
#include <vtk-8.1/vtkRenderer.h>
#include <vtk-8.1/vtkTransform.h>
#include <vtk-8.1/vtkAutoInit.h>
VTK_MODULE_INIT(vtkRenderingOpenGL2); // VTK was built with vtkRenderingOpenGL2
VTK_MODULE_INIT(vtkInteractionStyle);

namespace {
//
// Similar to Tutorial_Step2.cxx, we define a callback for interaction.
//
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
} // namespace

int main(int, char*[])
{
  vtkNew<vtkNamedColors> colors;

  vtkNew<vtkConeSource> cone;
  cone->SetHeight(3.0);
  cone->SetRadius(1.0);
  cone->SetResolution(10);

  vtkNew<vtkPolyDataMapper> coneMapper;
  coneMapper->SetInputConnection(cone->GetOutputPort());

  vtkNew<vtkActor> coneActor;
  coneActor->SetMapper(coneMapper);
  coneActor->GetProperty()->SetColor(colors->GetColor3d("Bisque").GetData());
  vtkNew<vtkRenderer> ren1;
  ren1->AddActor(coneActor);
  ren1->SetBackground(colors->GetColor3d("MidnightBlue").GetData());

  vtkNew<vtkRenderWindow> renWin;
  renWin->AddRenderer(ren1);
  renWin->SetSize(300, 300);
  renWin->SetWindowName("Tutorial_Step6");

  vtkNew<vtkRenderWindowInteractor> iren;
  iren->SetRenderWindow(renWin);

  vtkNew<vtkInteractorStyleTrackballCamera> style;
  iren->SetInteractorStyle(style);

  vtkNew<vtkBoxWidget> boxWidget;
  boxWidget->SetInteractor(iren);
  boxWidget->SetPlaceFactor(1.25);
  boxWidget->GetOutlineProperty()->SetColor(
      colors->GetColor3d("Gold").GetData());

  boxWidget->SetProp3D(coneActor);
  boxWidget->PlaceWidget();
  vtkNew<vtkMyCallback> callback;
  boxWidget->AddObserver(vtkCommand::InteractionEvent, callback);

  boxWidget->On();

  iren->Initialize();
  iren->Start();

  return EXIT_SUCCESS;
}
