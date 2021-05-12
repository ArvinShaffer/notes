#include <vtkActor.h>
#include <vtkCamera.h>
#include <vtkCylinderSource.h>
#include <vtkNamedColors.h>
#include <vtkNew.h>
#include <vtkPolyDataMapper.h>
#include <vtkProperty.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include <vtkAutoInit.h>
#include <vtkLight.h>
#include <vtkJPEGReader.h>
#include <vtkTexture.h>
#include <vtkPlaneSource.h>

VTK_MODULE_INIT(vtkRenderingOpenGL2); // VTK was built with vtkRenderingOpenGL2
VTK_MODULE_INIT(vtkInteractionStyle);
#include <array>

int main(int, char*[])
{
  vtkNew<vtkNamedColors> colors;

  std::array<unsigned char, 4> bkg{{26, 51, 102, 255}};
  colors->SetColor("BkgColor", bkg.data());

  vtkNew<vtkCylinderSource> cylinder;
  cylinder->SetResolution(8);

  vtkNew<vtkPolyDataMapper> cylinderMapper;
  cylinderMapper->SetInputConnection(cylinder->GetOutputPort());

  vtkNew<vtkActor> cylinderActor;
  cylinderActor->SetMapper(cylinderMapper);
  cylinderActor->GetProperty()->SetColor(
      colors->GetColor4d("Tomato").GetData());
  cylinderActor->RotateX(30.0);
  cylinderActor->RotateY(-45.0);

  vtkNew<vtkRenderer> renderer;
  renderer->AddActor(cylinderActor);
//renderer->SetBackground(colors->GetColor3d("BkgColor").GetData());
  //renderer->SetBackground(colors->GetColor3d("Write").GetData());
  renderer->SetBackground(1.0, 1.0, 1.0);

  vtkNew<vtkLight> myLight;
  myLight->SetColor(0,1,0);
  myLight->SetPosition(0,0,1);
  myLight->SetFocalPoint(renderer->GetActiveCamera()->GetFocalPoint());
  renderer->AddLight(myLight);
  vtkNew<vtkLight> myLight2;
  myLight2->SetColor(0,0,1);
  myLight2->SetPosition(0,0,-1);
  myLight2->SetFocalPoint( renderer->GetActiveCamera()->GetFocalPoint());
  renderer->AddLight(myLight2);

  vtkNew<vtkCamera> myCamera;
  myCamera->SetClippingRange(0.0475, 2.3786);
  myCamera->SetFocalPoint(0.0573, -0.2134, -0.0523);
  myCamera->SetPosition(0.3245, -0.1139, -0.2932);
  myCamera->SetViewUp(-0.2234, 0.9983, 0.0345);
  renderer->SetActiveCamera(myCamera);

  renderer->ResetCamera();
  renderer->GetActiveCamera()->Zoom(1.5);

  vtkNew<vtkRenderWindow> renderWindow;
  renderWindow->SetSize(300, 300);
  renderWindow->AddRenderer(renderer);
  renderWindow->SetWindowName("Cylinder");

  vtkNew<vtkRenderWindowInteractor> renderWindowInteractor;
  renderWindowInteractor->SetRenderWindow(renderWindow);
  renderWindow->Render();
  renderWindowInteractor->Start();

  vtkNew<vtkJPEGReader> reader;
  reader->SetFileName("..\\texture.j pg");
  vtkNew<vtkTexture> texture;
  texture->SetInputConnection(reader->GetOutputPort());
  texture->InterpolateOn();
  vtkNew<vtkPlaneSource> plane =
  vtkSmartPointer< vtkPlaneSource >::New。；
  vtkSmartPointer< vtkPolyDataMapper > mapper =
  vtkSmartPointer< vtkPolyDataMapper >::New。； mapper->SetInputConnection( plane->GetOutputPortO )； vtkSmartPointer< vtkActor > actor =
  vtkSmartPointer< vtkActor >::New。；
  actor->SetMapper( mapper);
  actor->SetTexture( texture );



  return EXIT_SUCCESS;
}
