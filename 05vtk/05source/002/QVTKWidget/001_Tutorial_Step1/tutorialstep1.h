#ifndef TUTORIALSTEP1_H
#define TUTORIALSTEP1_H

#include <QWidget>
#include <vtkActor.h>
#include <vtkCamera.h>
#include <vtkConeSource.h>
#include <vtkNamedColors.h>
#include <vtkNew.h>
#include <vtkPolyDataMapper.h>
#include <vtkProperty.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>

QT_BEGIN_NAMESPACE
namespace Ui { class TutorialStep1; }
QT_END_NAMESPACE

class TutorialStep1 : public QWidget
{
    Q_OBJECT

public:
    TutorialStep1(QWidget *parent = nullptr);
    ~TutorialStep1();

private:
    Ui::TutorialStep1 *ui;
};
#endif // TUTORIALSTEP1_H
