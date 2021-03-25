QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

LIBS += -ldl -lGLEW -lglfw -lGL -lX11 -lpthread -lXrandr -lXi

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        glad.c \
        main.cpp \
        stb_image.c

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    glad/glad.h \
    shader_s.h \
    stb_image.h

DISTFILES += \
    container.jpg
