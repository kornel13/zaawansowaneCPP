#ifndef BLOCK_H
#define BLOCK_H

#include <QGraphicsItemGroup>
#include <QVector>
#include <memory>
#include <QString>

#include "inputelement.h"
#include "outputelement.h"


class Block : public QGraphicsItemGroup
{
public /*enumerations*/:
    enum { Type = UserType + 10 };

public:
    Block();
    int whichInputCanBeConnected(QPointF point);
    bool canOutputBeConnected(QPointF point);

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
    std::shared_ptr<QGraphicsTextItem> text;

    void setBase();
    void setInputs(int number);
    void setOutput();
    void setText(QString name);

    QRectF getBaseRect() const;
    static const qreal SIZE;
};

#endif // BLOCK_H
