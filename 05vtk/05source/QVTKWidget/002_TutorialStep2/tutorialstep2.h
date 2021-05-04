#ifndef TUTORIALSTEP2_H
#define TUTORIALSTEP2_H

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
namespace Ui { class TutorialStep2; }
QT_END_NAMESPACE

class TutorialStep2 : public QWidget
{
    Q_OBJECT

public:
    TutorialStep2(QWidget *parent = nullptr);
    ~TutorialStep2();

private:
    Ui::TutorialStep2 *ui;
};
#endif // TUTORIALSTEP2_H
