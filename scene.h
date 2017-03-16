#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>

class QAction;
class QGraphicsLineItem;

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

    void filterBlockItems(QList<QGraphicsItem *> &list);

signals:
    void itemInserted(QPointF position);

public slots:
    void modeChanged(SceneMode mode);
};

#endif // SCENE_H
