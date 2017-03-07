#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>

class QAction;
class QGraphicsLineItem;

class Scene : public QGraphicsScene
{
    Q_OBJECT

public /*enumerations*/:
    enum Mode { MoveBlock, InsertConnection };

public:
    Scene(QObject *parent = 0);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent) override;

private:
    Mode mode;
    QGraphicsLineItem *currentLine;

    void filterBlockItems(QList<QGraphicsItem *> &list);

public slots:
    void modeChanged(QAction * action);
};

#endif // SCENE_H
