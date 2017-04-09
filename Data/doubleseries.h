#ifndef DOUBLESERIES_H
#define DOUBLESERIES_H

#include <type_traits>
#include <list>
#include <iostream>


class DoubleSeries
{
public:
    DoubleSeries(): DoubleSeries(0.0){}
    DoubleSeries(double val);
    DoubleSeries operator + (DoubleSeries other);
    DoubleSeries operator - (DoubleSeries other);
    DoubleSeries operator * (DoubleSeries other);
    DoubleSeries operator / (DoubleSeries other);

    void operator += (DoubleSeries other);
    void operator -= (DoubleSeries other);
    void operator *= (DoubleSeries other);
    void operator /= (DoubleSeries other);

    friend std::ostream& operator<<(std::ostream& s, const DoubleSeries& p);
    friend std::istream& operator>>(std::istream& s, DoubleSeries& p);

private:
    std::list<double> valueList;
};

namespace std
{
    template<>
    struct is_arithmetic<DoubleSeries>{
      static const bool value = true;
    };
}




#endif // DOUBLESERIES_H