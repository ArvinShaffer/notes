#include "tutorial_step4.h"
#include "ui_tutorial_step4.h"
#include <vtkAutoInit.h>
VTK_MODULE_INIT(vtkRenderingOpenGL2);
VTK_MODULE_INIT(vtkInteractionStyle);

Tutorial_Step4::Tutorial_Step4(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Tutorial_Step4)
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
    coneActor->GetProperty()->SetColor(0.2, 0.63, 0.79);
    coneActor->GetProperty()->SetDiffuse(0.7);
    coneActor->GetProperty()->SetSpecular(0.4);
    coneActor->GetProperty()->SetSpecularPower(20);

    vtkNew<vtkProperty> property;
    property->SetColor(colors->GetColor3d("Tomato").GetData());
    property->SetDiffuse(0.7);
    property->SetSpecular(0.4);
    property->SetSpecularPower(20);

    vtkNew<vtkActor> coneActor2;
    coneActor2->SetMapper(coneMapper);
    coneActor2->GetProperty()->SetColor(
                colors->GetColor3d("LightSeaGreen").GetData());
    coneActor2->SetProperty(property);
    coneActor2->SetPosition(0, 2, 0);

    vtkNew<vtkRenderer> ren1;
    ren1->AddActor(coneActor);
    ren1->AddActor(coneActor2);
    ren1->SetBackground(colors->GetColor3d("CornflowerBlue").GetData());

    vtkNew<vtkRenderWindow> renWin;
    renWin->AddRenderer(ren1);
    renWin->SetSize(300, 300);
    renWin->SetWindowName("Tutorial_Step4");
    ui->qvtkWidget->SetRenderWindow(renWin);
}

Tutorial_Step4::~Tutorial_Step4()
{
    delete ui;
}

