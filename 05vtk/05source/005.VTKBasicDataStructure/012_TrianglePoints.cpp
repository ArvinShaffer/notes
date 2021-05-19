#include <vtkNew.h>
#include <vtkPoints.h>
#include <vtkPolyData.h>
#include <vtkPolyDataWriter.h>
#include <vtkAutoInit.h>

VTK_MODULE_INIT(vtkRenderingOpenGL2); // VTK was built with vtkRenderingOpenGL2
VTK_MODULE_INIT(vtkInteractionStyle);

int main(int argc, char *argv[])
{
    vtkNew<vtkPoints> points;
    points->InsertNextPoint(1.0, 0.0, 0.0);
    points->InsertNextPoint(0.0, 0.0, 0.0);
    points->InsertNextPoint(0.0, 1.0, 0.0);

    vtkNew<vtkPolyData> polydata;

    polydata->SetPoints(points);
    vtkNew<vtkPolyDataWriter> writer;
    writer->SetFileName("triangle.vtk");
    writer->SetInputData(polydata);
    writer->Write();
    return EXIT_SUCCESS;
}
