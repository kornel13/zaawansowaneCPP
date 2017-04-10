#ifndef DATA_H
#define DATA_H

#include <type_traits>
#include <QString>
#include <sstream>
#include <string>
#include "Data/doubleseries.h"

/**
 * @class GenericData<T>
 * @brief Szablon klasy reprezentującej dane w obliczeniach.
 * @attention od autora: Tutaj lepiej byłoby użyć iterfejsu, nie szablonu klasy
 * jednakże, nie znalazłem lepszego miejsca, że wykorzystać mechanizmy progrmowania generycznego
 */
template< typename T = double,
          typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type>
class GenericData
{
public:
    /**
     * @brief Konstruktor
     * @param value dane
     */
    GenericData(T value): value(value), errorMsg("") {}

    /**
     * @brief Oeprator przypisania
     * @param other
     * @return GenericData<T>
     */
    GenericData<T>& operator = (const GenericData<T>& other)
    {  value = other.value;
        errorMsg = other.errorMsg;
        return *this;
    }

    /**
     * @brief Operator dodawania
     */
    GenericData<T> operator + (GenericData<T> other) { return GenericData( value + other.value); }

    /**
     * @brief Operator odejmowania
     */
    GenericData<T> operator - (GenericData<T> other) { return GenericData( value - other.value); }

    /**
     * @brief Operator mnożenia
     */
    GenericData<T> operator * (GenericData<T> other) { return GenericData( value * other.value); }

    /**
     * @brief Operator dzielenia
     */
    GenericData<T> operator / (GenericData<T> other) { return GenericData( value / other.value); }

    /**
     * @brief Operator dodawania i przypisania
     */
    void operator += (GenericData<T> other) { value += other.value; }

    /**
     * @brief Operator odejmowania i przypisania
     */
    void operator -= (GenericData<T> other) { value -= other.value; }

    /**
     * @brief Operator mnożenia i przypisania
     */
    void operator *= (GenericData<T> other) { value *= other.value; }

    /**
     * @brief Operator dzielenia i przypisania
     */
    void operator /= (GenericData<T> other) { value /= other.value; }

    /**
     * @brief Konwersja do QString
     * @return QString
     */
    QString toString()
    {
        std::stringstream stream;
        stream << value;

        return QString::fromStdString(stream.str());
    }

    /**
     * @brief Kowersja ze string. Zwraca false, gdy konwersja sie nie powiodła
     * @param str
     * @return bool wynik konwersji
     */
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

    /**
     * @brief Zwraca czy obiekt posiada prawidłowe dane
     * @return bool
     */
    bool isValid()
    {
        return errorMsg.isEmpty();
    }

    /**
     * @brief Ustawia treść wiadomości błędu
     * Oznacza to, że wystąpił błąd w obliczeniach
     * @param errorMsg
     */
    void setErrorMsg(QString errorMsg)
    {
        this->errorMsg = errorMsg;
    }

    /**
     * @brief Getter wiadomości błędu
     * @return QString
     */
    QString getErrMsg()
    {
        return errorMsg;
    }

    /**
     * @brief Kowersja do wskaźnika na IDataSeries
     * @return IDataSeries
     */
    IDataSeries* toIDataSeries()
    {
        return dynamic_cast<IDataSeries*>(&value);
    }

private:
     T value;
     QString errorMsg;

};

/**
 * @brief Alias aktualnie używanego typu w obliczeniach
 */
//typedef GenericData<double> Data
typedef GenericData<DoubleSeries> Data;

#endif // DATA_H
