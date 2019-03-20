#ifndef OpenGlBufferItem_H
#define OpenGlBufferItem_H
#include <QObject>
#include <QQuickFramebufferObject>
#include <QOpenGLFunctions>
#include <QOpenGLTexture>
#include <QOpenGLShaderProgram>
#include <QQuickWindow>
#include <QThreadPool>
#include <QRunnable>
#include <QMutex>
#include <QNetworkAccessManager>
#include <functional>
//#include "reactitem.h"

class OpenGlBufferItemRenderer: public QQuickFramebufferObject::Renderer, public QOpenGLFunctions { 
public:
    OpenGlBufferItemRenderer();
    void initOpenGl();
    void render() override;
    QOpenGLFramebufferObject* createFramebufferObject(const QSize &size) override;
    void updateData(unsigned char**data, int frameWidth, int frameHeight);
    void synchronize(QQuickFramebufferObject *item);

    
};

class OpenGlBufferItem: public QQuickFramebufferObject//, public ReactItem
{
    Q_OBJECT

public:
    Renderer *createRenderer() const;
    //void updateData(unsigned char**data);
    //void componentComplete();
    OpenGlBufferItem() {}
    void initialization();

    

private:
    OpenGlBufferItemRenderer * openGlBufferItemRenderer;

private slots:
    void parentWidthChanged(){
        setWidth(parentItem()->width());
    }
    void parentHeightChanged(){
        setHeight(parentItem()->height());
    }
    
};

#endif // OpenGlBufferItem_H
