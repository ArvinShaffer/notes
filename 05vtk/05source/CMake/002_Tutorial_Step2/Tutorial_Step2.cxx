#include <vtk-8.1/vtkActor.h>
#include <vtk-8.1/vtkCamera.h>
#include <vtk-8.1/vtkCommand.h>
#include <vtk-8.1/vtkConeSource.h>
#include <vtk-8.1/vtkNamedColors.h>
#include <vtk-8.1/vtkNew.h>
#include <vtk-8.1/vtkPolyDataMapper.h>
#include <vtk-8.1/vtkProperty.h>
#include <vtk-8.1/vtkRenderWindow.h>
#include <vtk-8.1/vtkRenderer.h>

#include <iostream>


namespace  {
class vtkMyCallback : public vtkCommand
{
public:
    static vtkMyCallback* New()
    {
        return new vtkMyCallback;
    }
    void Execute(vtkObject* caller, unsigned long, void*) override
    {
        auto renderer = reinterpret_cast<vtkRenderer*>(caller);
        std::cout << renderer->GetActiveCamera()->GetPosition()[0] << " "
                  << renderer->GetActiveCamera()->GetPosition()[1] << " "
                  << renderer->GetActiveCamera()->GetPosition()[2] << std::endl;
    }
    vtkMyCallback() = default;
};
}

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
    coneActor->GetProperty()->SetColor(colors->GetColor3d("MistyRose").GetData());

    vtkNew<vtkRenderer> ren1;
    ren1->AddActor(coneActor);
    ren1->SetBackground(colors->GetColor3d("MidnightBlue").GetData());
    ren1->ResetCamera();

    vtkNew<vtkRenderWindow> renWin;
    renWin->AddRenderer(ren1);
    renWin->SetSize(300, 300);
    renWin->SetWindowName("Tutorial_Step2");

    vtkNew<vtkMyCallback> mo1;
    ren1->AddObserver(vtkCommand::StartEvent, mo1);

    for(int i = 0; i < 360; ++i)
    {
        renWin->Render();
        ren1->GetActiveCamera()->Azimuth(1);
    }
    return EXIT_SUCCESS;
}
