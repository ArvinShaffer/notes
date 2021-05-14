#include <vtkNew.h>
#include <vtkBMPReader.h>
#include <vtkImageData.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkImageViewer2.h>
#include <vtkRenderWindow.h>
#include <vtkAutoInit.h>

VTK_MODULE_INIT(vtkRenderingOpenGL2); // VTK was built with vtkRenderingOpenGL2
VTK_MODULE_INIT(vtkInteractionStyle);

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        std::cout << argv[0] << " " << "BMP-File(*.bmp)" << std::endl;
        return EXIT_FAILURE;
    }
    vtkNew<vtkBMPReader> reader;
    std::cout << "Modification Time of reader (After New()):" << reader->GetMTime() << std::endl;
    reader->SetFileName(argv[1]);
    std::cout << "Modification Time of reader (After SetFileName()):" << reader->GetMTime() << std::endl;

    vtkImageData* imageData = reader->GetOutput();
    std::cout<<"Modification Time of reader (After GetOutput()): "<<reader->GetMTime()<<std::endl;
    reader->Update();
    std::cout<<"Modification Time of reader (After Update()): "<<reader->GetMTime()<<std::endl;

    int extent[6];
    imageData->GetExtent(extent);
    std::cout<<"Extent of image: "<<extent[0]<<" "
            <<extent[1]<<" "<<extent[2]<<" "<<extent[3]<<" "
           <<extent[4]<<" "<<extent[5]<<" "<<std::endl;

    vtkNew<vtkImageViewer2> viewer;
    vtkNew<vtkRenderWindowInteractor> interactor;
    viewer->SetupInteractor(interactor);
    viewer->SetInputData(imageData);
    viewer->Render();

    viewer->SetSize(640, 480);
    viewer->GetRenderWindow()->SetWindowName("vtkPipelineExecute");

    interactor->Initialize();
    interactor->Start();

    return EXIT_SUCCESS;
}
