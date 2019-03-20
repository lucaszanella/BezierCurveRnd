#include "beziercurvemanager.h"
#include "bridge.h"
#include "eventdispatcher.h"
#include "beziercurve.h"

#include <QCoreApplication>
#include <QDebug>
#include <QDesktopServices>
#include <QUrl>
#include <QFileOpenEvent>
#include "OpenGlBufferQtQuick.h"

namespace {
struct RegisterQMLMetaType {
  RegisterQMLMetaType() { qRegisterMetaType<BezierCurveManager *>(); }
} registerMetaType;
}
class BezierCurveManagerPrivate {
public:
  Bridge *bridge = nullptr;
};

BezierCurveManager::BezierCurveManager(QObject *parent)
    : ViewManager(parent), d_ptr(new BezierCurveManagerPrivate) {

}

ViewManager* BezierCurveManager::viewManager() {
    return this;
}

BezierCurveManager::~BezierCurveManager() {
}


QString BezierCurveManager::moduleName() { return "RCTBezierCurveManagerManager"; }

QQuickItem* BezierCurveManager::createView(const QVariantMap& properties) {
    OpenGlBufferItem* item = new OpenGlBufferItem();
    item->setWidth(200);
    item->setHeight(200);
    return item;
}


