#ifndef IEXPRESSION_H
#define IEXPRESSION_H

//#include "data.h"

typedef double Data;

struct IExpression
{
    virtual Data evaluate() = 0;
    virtual void addExpression(IExpression *expression, unsigned index) = 0;
    virtual void removeExpression(unsigned index) = 0;
    virtual bool isOutput() { return false; }
};

#endif // IEXPRESSION_H
