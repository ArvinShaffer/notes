#include <vtk-8.1/vtkActor.h>
#include <vtk-8.1/vtkCamera.h>
#include <vtk-8.1/vtkConeSource.h>
#include <vtk-8.1/vtkNamedColors.h>
#include <vtk-8.1/vtkNew.h>
#include <vtk-8.1/vtkPolyDataMapper.h>
#include <vtk-8.1/vtkProperty.h>
#include <vtk-8.1/vtkRenderWindow.h>
#include <vtk-8.1/vtkRenderer.h>
#include <vtk-8.1/vtkAutoInit.h>
VTK_MODULE_INIT(vtkRenderingOpenGL2); // VTK was built with vtkRenderingOpenGL2
VTK_MODULE_INIT(vtkInteractionStyle);

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
    ren1->SetBackground(colors->GetColor3d("RoyalBlue").GetData());
    ren1->SetViewport(0.0, 0.0, 0.5, 1.0);

    vtkNew<vtkRenderer> ren2;
    ren2->AddActor(coneActor);
    ren2->SetBackground(colors->GetColor3d("DodgerBlue").GetData());
    ren2->SetViewport(0.5, 0.0, 1.0, 1.0);

    vtkNew<vtkRenderWindow> renWin;
    renWin->AddRenderer(ren1);
    renWin->AddRenderer(ren2);
    renWin->SetSize(600, 300);
    renWin->SetWindowName("Tutorial_Step3");

    ren1->ResetCamera();
    ren1->GetActiveCamera()->Azimuth(90);

    for (int i = 0; i < 360; ++i)
    {
        // render the image
        renWin->Render();
        // rotate the active camera by one degree
        ren1->GetActiveCamera()->Azimuth(1);
        ren2->GetActiveCamera()->Azimuth(1);
    }


    return EXIT_SUCCESS;
}
