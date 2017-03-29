#ifndef IEXPRESSION_H
#define IEXPRESSION_H

#include "data.h"

class IExpression
{
public:
    virtual Data evaluate() = 0;
    virtual void addExpression(IExpression *expression, unsigned index) = 0;
    virtual void removeExpression(unsigned index) = 0;
    virtual void removeExpression(IExpression *expression) = 0;
    virtual void removeAllExpressions() = 0;
    virtual bool isOutput() { return false; }
    virtual void addOutput(IExpression *expression) = 0;
    virtual void removeOutput() = 0;
};

#endif // IEXPRESSION_H
