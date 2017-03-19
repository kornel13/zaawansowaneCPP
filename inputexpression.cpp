#include "inputexpression.h"
#include <QDebug>

Data InputExpression::evaluate()
{
    qDebug()<<"InputExpression::evaluate jestem\n";
    return 17.0;
}

void InputExpression::addExpression(IExpression *, unsigned)
{
}

void InputExpression::removeExpression(unsigned)
{
}
