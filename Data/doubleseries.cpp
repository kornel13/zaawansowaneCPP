#include "doubleseries.h"
#include <algorithm>
#include <iterator>
#include <functional>



DoubleSeries::DoubleSeries(double val)
{
    valueList.push_back(val);
}

std::ostream& operator<<(std::ostream& s, const DoubleSeries& ds)
{
    for(double value: ds.valueList)
        s << value << " ";
    return s;
}

std::istream& operator>>(std::istream& s, DoubleSeries& ds)
{
    ds.valueList.clear();
    std::copy(std::istream_iterator<double>(s),
              std::istream_iterator<double>(),
              std::inserter(ds.valueList, ds.valueList.begin()));
    s.clear();
    return s;
}

void DoubleSeries::operator += (DoubleSeries other)
{
    if(other.valueList.size() > valueList.size())
        valueList.resize(other.valueList.size(),0);

    std::transform(valueList.begin(), valueList.end(), other.valueList.begin(), valueList.begin(),std::plus<double>());
}

void DoubleSeries::operator -= (DoubleSeries other)
{
    if(other.valueList.size() > valueList.size())
        valueList.resize(other.valueList.size(),0);

    std::transform(valueList.begin(), valueList.end(), other.valueList.begin(), valueList.begin(),std::minus<double>());
}

void DoubleSeries::operator *= (DoubleSeries other)
{
    if(other.valueList.size() > valueList.size())
        valueList.resize(other.valueList.size(),1);

    std::transform(valueList.begin(), valueList.end(), other.valueList.begin(), valueList.begin(),std::multiplies<double>());
}

void DoubleSeries::operator /= (DoubleSeries other)
{
    if(other.valueList.size() > valueList.size())
        valueList.resize(other.valueList.size(),1);

    std::transform(valueList.begin(), valueList.end(), other.valueList.begin(), valueList.begin(),std::divides<double>());
}

DoubleSeries DoubleSeries::operator + (DoubleSeries other)
{
    DoubleSeries result;
    std::copy(valueList.begin(), valueList.end(), std::back_inserter(result.valueList));
    result += other;
    return result;

}

DoubleSeries DoubleSeries::operator - (DoubleSeries other)
{
    DoubleSeries result;
    std::copy(valueList.begin(), valueList.end(), std::back_inserter(result.valueList));
    result -= other;
    return result;
}

DoubleSeries DoubleSeries::operator * (DoubleSeries other)
{
    DoubleSeries result;
    std::copy(valueList.begin(), valueList.end(), std::back_inserter(result.valueList));
    result *= other;
    return result;
}

DoubleSeries DoubleSeries::operator / (DoubleSeries other)
{
    DoubleSeries result;
    std::copy(valueList.begin(), valueList.end(), std::back_inserter(result.valueList));
    result /= other;
    return result;
}

