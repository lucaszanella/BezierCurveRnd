#include "OpenGlBufferQtQuick.h"
#include <QOpenGLFramebufferObjectFormat>
#include <QRunnable>
#include <QEventLoop>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QMutexLocker>
#include <memory>
#include <iostream>
#include <QTimer>



OpenGlBufferItemRenderer::OpenGlBufferItemRenderer(){
}


void OpenGlBufferItemRenderer::render() {
    QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
    
    update();
}

QOpenGLFramebufferObject *OpenGlBufferItemRenderer::createFramebufferObject(const QSize &size)
{
    QOpenGLFramebufferObjectFormat format;
    format.setAttachment(QOpenGLFramebufferObject::CombinedDepthStencil);
    format.setSamples(16);
    return new QOpenGLFramebufferObject(size, format);
}

void OpenGlBufferItemRenderer::synchronize(QQuickFramebufferObject *item)
{
    OpenGlBufferItem *openGlBufferItem = static_cast<OpenGlBufferItem*>(item);

}

void OpenGlBufferItemRenderer::updateData(unsigned char**data, int frameWidth, int frameHeight)
{
    
}

QQuickFramebufferObject::Renderer *OpenGlBufferItem::createRenderer() const
{
    return new OpenGlBufferItemRenderer();
}