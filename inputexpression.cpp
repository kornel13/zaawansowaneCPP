#include "inputexpression.h"
#include <QDebug>

InputExpression::InputExpression(Data value)
    : value(value)
{
}

Data InputExpression::evaluate()
{
    qDebug()<<"InputExpression::evaluate jestem\n";
    return value;
}

void InputExpression::addExpression(IExpression *, unsigned)
{
}

void InputExpression::removeExpression(unsigned)
{
}
