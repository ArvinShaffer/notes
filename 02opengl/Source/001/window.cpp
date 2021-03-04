#include "window.h"
#include <QtCore/QCoreApplication>

#include <QtGui/QOpenGLContext>
#include <QtGui/QOpenGLPaintDevice>
#include <QtGui/QPainter>

//! [1]
Window::Window(QOpenGLWindow *parent)
    : //QOpenGLWindow(parent)
     m_animating(false)
    , m_context(0)
    , m_device(0)
{
    setSurfaceType(QOpenGLWindow::OpenGLSurface);
}
//! [1]

Window::~Window()
{
    delete m_device;
}
//! [2]
void Window::render(QPainter *painter)
{
    Q_UNUSED(painter);
}

void Window::initialize()
{
}

void Window::render()
{
    if (!m_device)
        m_device = new QOpenGLPaintDevice;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

    m_device->setSize(size() * devicePixelRatio());
    m_device->setDevicePixelRatio(devicePixelRatio());

    QPainter painter(m_device);
    render(&painter);
}
//! [2]

//! [3]
void Window::renderLater()
{
    requestUpdate();
}

bool Window::event(QEvent *event)
{
    switch (event->type()) {
    case QEvent::UpdateRequest:
        renderNow();
        return true;
    default:
        return QWindow::event(event);
    }
}

void Window::exposeEvent(QExposeEvent *event)
{
    Q_UNUSED(event);

    if (isExposed())
        renderNow();
}
//! [3]

//! [4]
void Window::renderNow()
{
    if (!isExposed())
        return;

    bool needsInitialize = false;

    if (!m_context) {
        m_context = new QOpenGLContext(this);
        m_context->setFormat(requestedFormat());
        m_context->create();

        needsInitialize = true;
    }

    m_context->makeCurrent(this);

    if (needsInitialize) {
        initializeOpenGLFunctions();
        initialize();
    }

    render();

    m_context->swapBuffers(this);

    if (m_animating)
        renderLater();
}
//! [4]

//! [5]
void Window::setAnimating(bool animating)
{
    m_animating = animating;

    if (animating)
        renderLater();
}
//! [5]
