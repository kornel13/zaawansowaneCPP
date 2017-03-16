#ifndef SUMEXPRESSION_H
#define SUMEXPRESSION_H

#include "iexpression.h"

#include <QList>

class SumExpression : public IExpression
{
public:
    SumExpression() = default;
    Data evaluate();

    void addExpression(IExpression *expression);

private:
    QList<IExpression*> inputs;
};

#endif // SUMEXPRESSION_H
