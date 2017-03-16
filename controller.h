#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QPointF>
#include "scene.h"

class ItemFactory;
class QActionGroup;

class Controller: public QObject
{
    Q_OBJECT
public:
    Controller(Scene *scene, QObject *parent = nullptr);
    QList<ItemFactory*> getItemFactory();

signals:
    void sceneModeChanged(SceneMode mode);

public slots:
    void actionChanged(QAction* action);
    void buttonChanged(int id);
    void itemInserted(QPointF position);

private:
    void addItemFactory(ItemFactory* itemFactory);

    Scene *scene;
    QActionGroup *actionGroup;
    QList<ItemFactory*> itemFactoryList;
    ItemFactory* selectedItemFactory;
};

#endif // CONTROLLER_H
