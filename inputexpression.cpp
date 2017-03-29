#include "inputexpression.h"
#include <QDebug>

InputExpression::InputExpression(Data value)
    : value(value), output(nullptr)
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

void InputExpression::removeExpression(IExpression *expression)
{

}

void InputExpression::removeAllExpressions()
{
    if(output) output->removeExpression(this);
}

void InputExpression::addOutput(IExpression *expression)
{
    output = expression;
}

void InputExpression::removeOutput()
{
    output = nullptr;
}
