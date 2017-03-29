#ifndef ARITHMETICEXPRESSION_H
#define ARITHMETICEXPRESSION_H

#include "iexpression.h"
#include <QVector>

class ArithmeticExpression : public IExpression
{
public:
    ArithmeticExpression(unsigned inputsNumber);
    Data evaluate() = 0;
    void addExpression(IExpression *expression, unsigned index);
    void removeExpression(unsigned index);
    void removeExpression(IExpression *expression);
    void removeAllExpressions();
    virtual void addOutput(IExpression *expression);
    virtual void removeOutput();

    QVector<IExpression*> inputs;
    IExpression* output;
};

#endif // ARITHMETICEXPRESSION_H
