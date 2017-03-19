#ifndef OUTPUTEXPRESSION_H
#define OUTPUTEXPRESSION_H

#include "iexpression.h"

class OutputExpression : public IExpression
{
public:
    OutputExpression() = default;
    Data evaluate();
    void addExpression(IExpression *expression, unsigned);
    void removeExpression(unsigned index);
    bool isOutput() override;

private:
    IExpression *input;
};

#endif // OUTPUTEXPRESSION_H
