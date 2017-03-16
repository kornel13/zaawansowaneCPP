#ifndef DIFFERENCEEXPRESSION_H
#define DIFFERENCEEXPRESSION_H

#include "iexpression.h"

#include <QList>

class DifferenceExpression : public IExpression
{
public:
    DifferenceExpression() = default;
    Data evaluate();

    void addExpression(IExpression *expression);

private:
    QList<IExpression*> inputs;
};

#endif // DIFFERENCEEXPRESSION_H
