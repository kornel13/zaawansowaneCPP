#ifndef GRAPHICSITEM_H
#define GRAPHICSITEM_H

#include <QGraphicsItemGroup>
#include <QVector>
#include <memory>
#include <QString>

#include "inputelement.h"
#include "outputelement.h"

typedef QGraphicsSimpleTextItem Icon;

class GraphicsItem : public QGraphicsItemGroup
{
public /*enumerations*/:
    enum { Type = UserType + 10 };

public:
    GraphicsItem(unsigned inputsNumber, unsigned outputNumber, QString className, QString itemName, QString icon);
    int whichInputCanBeConnected(QPointF point);
    int getInputIndex(Connection* connection);
    bool canOutputBeConnected(QPointF point);
    void removeConnection(Connection* connection);
    void removeAllConnections();
    QList<Connection*> getAllConnections();

    std::shared_ptr<OutputElement> getOutput() const
    {
        return output;
    }

    std::shared_ptr<InputElement> getInput(int index) const
    {
        if(index >= 0 && index < inputs.size() )
        {
            return inputs[index];
        }
        return nullptr;
    }

    int type() const override { return Type; }
    QRectF getBaseRect() const;

private:
    QVector< std::shared_ptr<InputElement> > inputs;
    std::shared_ptr<OutputElement> output;
    std::shared_ptr<QGraphicsRectItem> base;

    std::shared_ptr<QGraphicsSimpleTextItem> className;
    std::shared_ptr<QGraphicsSimpleTextItem> itemName;
    std::shared_ptr<Icon> icon;



    void setBase();
    void setInputs(int number);
    void setOutput();
    void setClassAndItemNames(QString className, QString itemName);
    void setIcon(QString itemString);

    void centerSubitem(std::shared_ptr<QGraphicsItem> item);
    void moveByY(std::shared_ptr<QGraphicsItem> item, qreal dy);


    static const qreal SIZE;


};

#endif // GRAPHICSITEM_H
