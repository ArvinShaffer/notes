#include "tutorialstep2.h"
#include "ui_tutorialstep2.h"
#include <vtkAutoInit.h>
VTK_MODULE_INIT(vtkRenderingOpenGL2);
VTK_MODULE_INIT(vtkInteractionStyle);

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
                  << renderer->GetActiveCamera()->GetPosition()[2] << " " << std::endl;
    }
    vtkMyCallback() = default;
};
}


TutorialStep2::TutorialStep2(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TutorialStep2)
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
    ren1->SetBackground(colors->GetColor3d("MidnightBlue").GetData());
    ren1->ResetCamera();

    vtkNew<vtkRenderWindow> renWin;
    renWin->AddRenderer(ren1);
    renWin->SetSize(300, 300);
    renWin->SetWindowName("Tutorial_Step2");

    vtkNew<vtkMyCallback> mo1;
    ren1->AddObserver(vtkCommand::StartEvent, mo1);

    ui->qvtkWidget->SetRenderWindow(renWin);
}

TutorialStep2::~TutorialStep2()
{
    delete ui;
}

















