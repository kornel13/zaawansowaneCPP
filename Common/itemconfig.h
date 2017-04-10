#ifndef ITEMCONFIG_H
#define ITEMCONFIG_H


#include <QMap>
#include <QList>
#include <QPair>
#include <QString>
#include <functional>

/**
 * @brief Określa typ danych w konfiguracji
 * Jak wartość jest typu DataType używanego w obliczeniach
 * bazuje w walidacji na metodzie konwersji ze QString z samej klasy danych
 */
enum ConfigType { DataType, OtherType};
/**
 * @brief Alias na pare funktora walidującego i konfiguracji walidacji
 */
using ValuePair = QPair<QString, std::function<bool(QString)> >;

/**
 * @brief Mapa nazw pól w strukturze konfiguracji na walidatora
 */
using ConfigMap = QMap<QString,  ValuePair>;

/**
 * @class ItemConfig
 * @brief Klasa reprezentuje konfigurację, wraz jej strukturą
 * dla danego bloku. Klasa generuje również walidatory wartości wejściowych
 * dla konfiguracji bazują na informacji odstarczonych z zewnątrz
 */
class ItemConfig
{
public:
    /**
     * @brief Konstruktor
     */
    ItemConfig();

    /**
     * @brief Dodaje wartość w strukturze konfiguracyjnej
     * @param name Nazwa pola
     * @param value Wartośc pola
     * @param type Typ pola
     * @param validateRegexp Walidujące wyrażenie regularne
     */
    void addValue(QString name, QString value, ConfigType type, QString validateRegexp = "");

    /**
     * @brief Ustawia już istniejącą wartośc w strukturze konfiguracyjej
     * @param name Nazwa pola
     * @param value wartośc pola
     */
    void setValue(QString name, QString value);

    /**
     * @brief Pobiera wartość pola o przekazanej nazwie
     *
     * @param name Nazwa pola
     * @return QString Wartość pola
     */
    QString getValue(QString name);

    /**
     * @brief Zwraca wyniki walidacji przekazanej wartośći dla danego typu
     * pola w strukturze
     *
     * @param name Nazwa pola pod które wykonywana jest próba zapisu wartości
     * @param value przekazana wartość
     * @return bool Wynik walidacji
     */
    bool validate(QString name, QString value);

    /**
     * @brief Zwaraca liste nazw
     *
     * @return QList<QString>
     */
    QList<QString> getKeys() { return map.keys(); }

    /**
     * @brief Getter nazwy klasy bloków
     * @return QString
     */
    QString getClassName() { return className; }

    /**
     * @brief Setter nazwy klasy bloków
     * @param name
     */
    void setClassName(QString name) { this->className = name; }

private:
     ConfigMap map;
     QString className;

     std::function<bool(QString)> getValidator(ConfigType type, QString validateRegexp = "");


};

#endif // ITEMCONFIG_H
