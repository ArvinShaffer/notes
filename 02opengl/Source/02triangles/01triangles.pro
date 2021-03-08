QT += gui core

CONFIG += c++11 console
CONFIG -= app_bundle


#INCLUDEPATH += /home/icuipi/Programs/Opengl/library/include /usr/local/include/gl3w/GL/gl3w.h

#LIBS += -L/home/icuipi/Programs/Opengl/library/lib -lglfw
LIBS += -lglfw -ldl
# LIBS += /usr/local/lib/libglfw3.a -ldl

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        LoadShaders.cpp \
        gl3w.c \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    GL/glcorearb.h \
    GL/glext.h \
    GL3/gl3.h \
    GL3/gl3w.h \
    LoadShaders.h \
    vgl.h
