#include <vtkConeSource.h>
#include <vtkCubeSource.h>
#include <vtkCylinderSource.h>
#include <vtkSphereSource.h>
#include <vtkPolyDataMapper.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkActor.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkNew.h>
#include <vtkAutoInit.h>
VTK_MODULE_INIT(vtkRenderingOpenGL2); // VTK was built with vtkRenderingOpenGL2
VTK_MODULE_INIT(vtkInteractionStyle);

int main()
{
    vtkNew<vtkConeSource> cone;
    vtkNew<vtkCubeSource> cube;
    vtkNew<vtkCylinderSource> cylinder;
    vtkNew<vtkSphereSource> sphere;

    vtkNew<vtkPolyDataMapper> coneMapper;
    coneMapper->SetInputConnection(cone->GetOutputPort());
    vtkNew<vtkPolyDataMapper> cubeMapper;
    cubeMapper->SetInputConnection(cube->GetOutputPort());
    vtkNew<vtkPolyDataMapper> cylinderMapper;
    cylinderMapper->SetInputConnection(cylinder->GetOutputPort());
    vtkNew<vtkPolyDataMapper> sphereMapper;
    sphereMapper->SetInputConnection(sphere->GetOutputPort());

    vtkNew<vtkActor> coneActor;
    coneActor->SetMapper(coneMapper);
    vtkNew<vtkActor> cubeActor;
    cubeActor->SetMapper(cubeMapper);
    vtkNew<vtkActor> cylinderActor;
    cylinderActor->SetMapper(cylinderMapper);
    vtkNew<vtkActor> sphereActor;
    sphereActor->SetMapper(sphereMapper);


    vtkNew<vtkRenderer> renderer1;
    renderer1->AddActor(coneActor);
    renderer1->SetBackground(1.0,0.0,0.0);
    renderer1->SetViewport(0.0,0.0,0.5,0.5);
    vtkNew<vtkRenderer> renderer2;
    renderer2->AddActor(cubeActor);
    renderer2->SetBackground(0.0,1.0,0.0);
    renderer2->SetViewport(0.5,0.0,1.0,0.5);
    vtkNew<vtkRenderer> renderer3;
    renderer3->AddActor(cylinderActor);
    renderer3->SetBackground(0.0,0.0,1.0);
    renderer3->SetViewport(0.0,0.5,0.5,1.0);
    vtkNew<vtkRenderer> renderer4;
    renderer4->AddActor(sphereActor);
    renderer4->SetBackground(1.0,1.0,0.0);
    renderer4->SetViewport(0.5,0.5,1.0,1.0);

    vtkNew<vtkRenderWindow> renWin;
    renWin->AddRenderer(renderer1);
    renWin->AddRenderer(renderer2);
    renWin->AddRenderer(renderer3);
    renWin->AddRenderer(renderer4);
    renWin->SetSize( 640, 480 );
    renWin->Render();
    renWin->SetWindowName("Viewport");

    vtkNew<vtkRenderWindowInteractor> interactor;
    interactor->SetRenderWindow(renWin);

    renWin->Render();
    interactor->Initialize();
    interactor->Start();

    return EXIT_SUCCESS;
}
