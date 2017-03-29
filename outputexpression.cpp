#include "outputexpression.h"
#include <QDebug>

OutputExpression::OutputExpression()
{
    input = nullptr;
}

void OutputExpression::addExpression(IExpression *expression, unsigned)
{
    input = expression;
    expression->addOutput(this);
}

void OutputExpression::removeExpression(unsigned)
{
    input->removeOutput();
    input = nullptr;
}

void OutputExpression::removeExpression(IExpression *)
{
    input->removeOutput();
    input = nullptr;
}

void OutputExpression::removeAllExpressions()
{
    removeExpression(nullptr);
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

void OutputExpression::addOutput(IExpression *expression)
{
}

void OutputExpression::removeOutput()
{
}


