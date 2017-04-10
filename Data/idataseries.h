#ifndef IDATASERIES_H
#define IDATASERIES_H

#include <list>


class IDataSeries
{
public:
    virtual std::list<double> getList() = 0;
};


#endif // IDATASERIES_H
