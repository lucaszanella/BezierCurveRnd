#ifndef BezierCurveManager_H
#define BezierCurveManager_H

#include "componentmanagers/viewmanager.h"
#include "moduleinterface.h"

#include <QVariantMap>


class BezierCurveManagerPrivate;
class BezierCurveManager : public ViewManager {
    Q_OBJECT
    Q_INTERFACES(ModuleInterface)

    Q_DECLARE_PRIVATE(BezierCurveManager)

public:
    Q_INVOKABLE BezierCurveManager(QObject* parent = 0);
    ~BezierCurveManager();

    virtual ViewManager* viewManager() override;
    virtual QString moduleName() override;

protected:
    virtual QQuickItem* createView(const QVariantMap& properties) override;

private:
    QScopedPointer<BezierCurveManagerPrivate> d_ptr;

};

#endif // BezierCurveManager_H
