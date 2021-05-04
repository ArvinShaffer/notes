#include "tutorialstep1.h"
#include "ui_tutorialstep1.h"
#include <vtkAutoInit.h>
VTK_MODULE_INIT(vtkRenderingOpenGL2); // VTK was built with vtkRenderingOpenGL2
VTK_MODULE_INIT(vtkInteractionStyle);

TutorialStep1::TutorialStep1(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TutorialStep1)
{
    ui->setupUi(this);
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
      //ren1->SetBackground(colors->GetColor3d("MidnightBlue").GetData());
      ren1->SetBackground(1, 1, 1);

      vtkNew<vtkRenderWindow> renWin;
      renWin->AddRenderer(ren1);
      renWin->SetSize(300, 300);
      renWin->SetWindowName("Tutorial_Step1");

      ui->qvtkWidget->SetRenderWindow(renWin);
}

TutorialStep1::~TutorialStep1()
{
    delete ui;
}

