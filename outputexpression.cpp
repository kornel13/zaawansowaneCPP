#include "outputexpression.h"
#include <QDebug>

void OutputExpression::addExpression(IExpression *expression, unsigned)
{
    input = expression;
}

void OutputExpression::removeExpression(unsigned index)
{
    input = nullptr;
}

Data OutputExpression::evaluate()
{
#include <QDebug>
    qDebug()<<"OutputExpression::evaluate jestem\n";
    return input->evaluate();
}

bool OutputExpression::isOutput()
{
    return true;
}


