#include <vtkNew.h>
#include <vtkStructuredPointsReader.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkMarchingCubes.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkAutoInit.h>

VTK_MODULE_INIT(vtkRenderingOpenGL2); // VTK was built with vtkRenderingOpenGL2
VTK_MODULE_INIT(vtkInteractionStyle);

int main(int argc, char* argv[])
{
    if (argc < 2){
        std::cout << argv[0] << " " << "VTK-File(*.vtk)" << std::endl;
        return EXIT_FAILURE;
    }
    //读入Structured_Points 类型的vtk 文件
    vtkNew<vtkStructuredPointsReader> reader;
    reader->SetFileName(argv[1]);

    //用移动立方体法提取等值面
    vtkNew<vtkMarchingCubes> marchingCubes;
    marchingCubes->SetInputConnection(reader->GetOutputPort());
    marchingCubes->SetValue(0, 500);

    //将生成的等值面数据进行Mapper
    vtkNew<vtkPolyDataMapper> mapper;
    mapper->SetInputConnection(marchingCubes->GetOutputPort());

    //把Mapper的输出送入渲染引擎进行显示
    //渲染引擎部分
    vtkNew<vtkActor> actor;
    actor->SetMapper(mapper);
    vtkNew<vtkRenderer> renderer;
    renderer->AddActor(actor);
    renderer->SetBackground(1.0, 1.0, 1.0);
    vtkNew<vtkRenderWindow> renWin;
    renWin->AddRenderer(renderer);
    renWin->SetSize(640, 480);
    renWin->Render();
    renWin->SetWindowName("vtkPipeLineDemo");

    vtkNew<vtkRenderWindowInteractor> interactor;
    interactor->SetRenderWindow(renWin);
    interactor->Initialize();
    interactor->Start();

    return EXIT_SUCCESS;
}
