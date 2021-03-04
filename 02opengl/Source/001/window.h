#ifndef WINDOW_H
#define WINDOW_H

#include <QOpenGLWindow>
#include <QtGui/QOpenGLFunctions>

QT_BEGIN_NAMESPACE
class QPainter;
class QOpenGLContext;
class QOpenGLPaintDevice;
QT_END_NAMESPACE

class Window : public QOpenGLWindow, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    explicit Window(QOpenGLWindow *parent = 0);
    ~Window();

    virtual void render(QPainter *painter);
    virtual void render();

    virtual void initialize();

    void setAnimating(bool animating);

public slots:
    void renderLater();
    void renderNow();

protected:
    bool event(QEvent *event) override;

    void exposeEvent(QExposeEvent *event) override;

private:
    bool m_animating;

    QOpenGLContext *m_context;
    QOpenGLPaintDevice *m_device;
};

#endif // WINDOW_H
