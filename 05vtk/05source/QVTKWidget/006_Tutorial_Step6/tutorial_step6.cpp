#include "tutorial_step6.h"
#include "ui_tutorial_step6.h"

Tutorial_Step6::Tutorial_Step6(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Tutorial_Step6)
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
    //iren->Start();
    this->ui->qvtkWidget->SetRenderWindow(renWin);
}

Tutorial_Step6::~Tutorial_Step6()
{
    delete ui;
}

