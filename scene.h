#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QPair>
#include "itemconfig.h"

class QAction;
class QGraphicsLineItem;
class GraphicsItem;

enum SceneMode { MoveBlock, InsertConnection, InsertItem };

class Scene : public QGraphicsScene
{
    Q_OBJECT  
public:
    Scene(QObject *parent = 0);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent) override;

private:
    SceneMode mode;
    QGraphicsLineItem *currentLine;
    QPair<bool, ItemConfig> currentConfig;

    void filterBlockItems(QList<QGraphicsItem *> &list);

signals:
    void itemInserted(QPointF position, ItemConfig config);
    void connectionInserted(GraphicsItem* start, unsigned outId,
                            GraphicsItem* end, unsigned inId);

public slots:
    void modeChanged(SceneMode mode);
    void appliedConfig(ItemConfig config);
};

#endif // SCENE_H
