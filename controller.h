#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QPointF>
#include <QHash>

#include  "iexpression.h"
#include "scene.h"
#include "itemconfig.h"
#include "itemattributesdialog.h"

class ItemFactory;
class QActionGroup;

class Controller: public QObject
{
    Q_OBJECT
public:
    Controller(Scene *scene, QObject *parent = nullptr);
    QList<ItemFactory*> getItemFactory();
    QHash<int, ItemAttributesDialog *> *getItemAttributesDialogs();

signals:
    void sceneModeChanged(SceneMode mode);
    void setOutputText(QString);
    void appliedConfig(ItemConfig);
    void enableOutput(bool enable);

public slots:
    void actionChanged(QAction* action);
    void itemToAdd(int id, ItemConfig config);
    void itemInserted(QPointF position, ItemConfig config);
    void itemToDelete();
    void  calculate(bool);
    void connectionInserted(GraphicsItem *start, unsigned outId,
                            GraphicsItem *end, unsigned inId);

private:
    void addItemFactory(ItemFactory* itemFactory);

    Scene *scene;
    QActionGroup *actionGroup;
    QList<ItemFactory*> itemFactoryList;
    QHash<int, ItemAttributesDialog*> itemAttributesDialogHash;
    ItemFactory* selectedItemFactory;
    IExpression* outputExpression;
};

#endif // CONTROLLER_H
