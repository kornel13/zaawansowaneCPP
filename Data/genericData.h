#ifndef DATA_H
#define DATA_H

#include <type_traits>
#include <QString>
#include <sstream>
#include <string>
#include "Data/doubleseries.h"

template< typename T = double,
          typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type>
class GenericData
{
public:
    GenericData(T value): value(value), errorMsg("") {}

    GenericData<T>& operator = (const GenericData<T>& other)
    {  value = other.value;
        errorMsg = other.errorMsg;
        return *this;
    }

    GenericData<T> operator + (GenericData<T> other) { return GenericData( value + other.value); }
    GenericData<T> operator - (GenericData<T> other) { return GenericData( value - other.value); }
    GenericData<T> operator * (GenericData<T> other) { return GenericData( value * other.value); }
    GenericData<T> operator / (GenericData<T> other) { return GenericData( value / other.value); }

    void operator += (GenericData<T> other) { value += other.value; }
    void operator -= (GenericData<T> other) { value -= other.value; }
    void operator *= (GenericData<T> other) { value *= other.value; }
    void operator /= (GenericData<T> other) { value /= other.value; }

    QString toString()
    {
        std::stringstream stream;
        stream << value;

        return QString::fromStdString(stream.str());
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

    bool isValid()
    {
        return errorMsg.isEmpty();
    }

    void setErrorMsg(QString errorMsg)
    {
        this->errorMsg = errorMsg;
    }

    QString getErrMsg()
    {
        return errorMsg;
    }

    IDataSeries* toIDataSeries()
    {
        return dynamic_cast<IDataSeries*>(&value);
    }

private:
     T value;
     QString errorMsg;

};

typedef GenericData<DoubleSeries> Data;

#endif // DATA_H
