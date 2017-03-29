#ifndef GRAPHICSITEM_H
#define GRAPHICSITEM_H

#include <QGraphicsItemGroup>
#include <QVector>
#include <memory>
#include <QString>

#include "inputelement.h"
#include "outputelement.h"

typedef QGraphicsTextItem Icon;

class GraphicsItem : public QGraphicsItemGroup
{
public /*enumerations*/:
    enum { Type = UserType + 10 };

public:
    GraphicsItem(unsigned inputsNumber, unsigned outputNumber);
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

private:
    QVector< std::shared_ptr<InputElement> > inputs;
    std::shared_ptr<OutputElement> output;
    std::shared_ptr<QGraphicsRectItem> base;

    std::shared_ptr<QGraphicsTextItem> className;
    std::shared_ptr<QGraphicsTextItem> itemName;
    std::shared_ptr<Icon> icon;



    void setBase();
    void setInputs(int number);
    void setOutput();
    void setTexts(QString className, QString itemName);
    void setIcon();

    QRectF getBaseRect() const;
    static const qreal SIZE;


};

#endif // GRAPHICSITEM_H
