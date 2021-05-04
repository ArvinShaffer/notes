#include <vtk-8.1/vtkActor.h>
#include <vtk-8.1/vtkCamera.h>
#include <vtk-8.1/vtkConeSource.h>
#include <vtk-8.1/vtkNamedColors.h>
#include <vtk-8.1/vtkNew.h>
#include <vtk-8.1/vtkPolyDataMapper.h>
#include <vtk-8.1/vtkProperty.h>
#include <vtk-8.1/vtkRenderWindow.h>
#include <vtk-8.1/vtkRenderer.h>


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

    vtkNew<vtkRenderWindow> renWin;
    renWin->AddRenderer(ren1);
    renWin->SetSize(300, 300);
    renWin->SetWindowName("Tutorial_Step1");

    for (int i = 0; i < 360; ++i)
    {
        renWin->Render();
        ren1->GetActiveCamera()->Azimuth(1);
    }
    return EXIT_SUCCESS;
}
