QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += /usr/local/include/vtk-8.1


LIBS += -L/usr/local/lib \
  -lvtkCommonExecutionModel-8.1 \
  -lvtkCommonColor-8.1 \
  -lvtkCommonCore-8.1 \
  -lvtkFiltersSources-8.1 \
  -lvtkInteractionStyle-8.1 \
  -lvtkRenderingContextOpenGL2-8.1 \
  -lvtkRenderingCore-8.1 \
  -lvtkRenderingFreeType-8.1 \
  -lvtkRenderingGL2PSOpenGL2-8.1 \
  -lvtkRenderingOpenGL2-8.1  \
  -lvtkCommonTransforms-8.1 \
  -lvtkInteractionWidgets-8.1 \
  -lvtkCommonMisc-8.1   \
  -lvtkFiltersCore-8.1 \
  -lvtkIOLegacy-8.1    \
  -lvtkIOImage-8.1 \
  -lvtkInteractionImage-8.1

SOURCES += \
    010__vtkPipelineExecute.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
