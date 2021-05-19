#include <vtkPoints.h>
#include <vtkLine.h>
#include <vtkCellArray.h>
#include <vtkSmartPointer.h>
#include <vtkPolyDataWriter.h>
#include <vtkPolyData.h>
#include <vtkAutoInit.h>

VTK_MODULE_INIT(vtkRenderingOpenGL2); // VTK was built with vtkRenderingOpenGL2
VTK_MODULE_INIT(vtkInteractionStyle);

int main(int argc, char *argv[])
{
    //创建三个坐标点
    vtkNew<vtkPoints> points;
    points->InsertNextPoint ( 1.0, 0.0, 0.0 ); //返回第一个点的ID：0
    points->InsertNextPoint ( 0.0, 0.0, 1.0 ); //返回第二个点的ID：1
    points->InsertNextPoint ( 0.0, 0.0, 0.0 ); //返回第三个点的ID：2
    //每两个坐标点之间分别创建一条线
    //SetId()的第一个参数是线段的端点ID，第二个参数是连接的点的ID
    vtkNew<vtkLine> line0;
    line0->GetPointIds()->SetId ( 0,0 );
    line0->GetPointIds()->SetId ( 1,1 );
    vtkNew<vtkLine> line1;
    line1->GetPointIds()->SetId ( 0,1 );
    line1->GetPointIds()->SetId ( 1,2 );
    vtkNew<vtkLine> line2;
    line2->GetPointIds()->SetId ( 0,2 );
    line2->GetPointIds()->SetId ( 1,0 );
    //创建Cell数组，用于存储以上创建的线段
    vtkNew<vtkCellArray> lines;
    lines->InsertNextCell (line0);
    lines->InsertNextCell (line1);
    lines->InsertNextCell (line2);
    vtkNew<vtkPolyData> polydata;
    //将点和线加入到数据集中，前者指定数据集的几何，后者指定其拓扑
    polydata->SetPoints ( points );
    polydata->SetLines ( lines );
    vtkNew<vtkPolyDataWriter> writer;
    writer->SetFileName ( "TriangleLines.vtk" );
    writer->SetInputData(polydata);
    writer->Write();
    return EXIT_SUCCESS;
}

