#ifndef DATA_H
#define DATA_H

#include <type_traits>
#include <QString>
#include <sstream>
#include <string>

template< typename T = double,
          typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type>
class GenericData
{
public:
    GenericData(T value): value(value) {}

    GenericData<T>& operator = (const GenericData<T>& other)
    {  value = other.value;
        return *this;
    }

    GenericData<T> operator + (GenericData<T> other) { return GenericData( value +other.value); }
    GenericData<T> operator - (GenericData<T> other) { return GenericData( value -other.value); }
    GenericData<T> operator * (GenericData<T> other) { return GenericData( value *other.value); }
    GenericData<T> operator / (GenericData<T> other) { return GenericData( value /other.value); }
    GenericData<T> operator % (GenericData<T> other) { return GenericData( value %other.value); }

    void operator += (GenericData<T> other) { value +=other.value; }
    void operator -= (GenericData<T> other) { value -=other.value; }
    void operator *= (GenericData<T> other) { value *=other.value; }
    void operator /= (GenericData<T> other) { value /=other.value; }
    void operator %= (GenericData<T> other) { value %=other.value; }

    // conditions
    bool operator == (GenericData<T> other) { return value ==other.value; }
    bool operator != (GenericData<T> other) { return value !=other.value; }
    bool operator > (GenericData<T> other) { return value >other.value; }
    bool operator < (GenericData<T> other) { return value <other.value; }
    bool operator >= (GenericData<T> other) { return value >=other.value; }
    bool operator <= (GenericData<T> other) { return value <=other.value; }

    QString toString()
    {
        std::stringstream stream;
        std::string result;

        stream << value;
        stream >> result;

        return QString::fromStdString(result);
    }

    bool fromString(QString str)
    {
        std::stringstream stream;

        stream << str.toStdString();
        stream >> value;

        if (stream.fail()) {
            stream.clear();
            return false;
        }
        return true;
    }

private:
     T value;

};

typedef GenericData<double> Data;

#endif // DATA_H
