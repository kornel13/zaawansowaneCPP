#ifndef ITEMNAMEPROVIDER_H
#define ITEMNAMEPROVIDER_H

#include <QString>

/**
 * @class ItemNameProvider
 * @brief Pomocnicza klasa generująca domyślne nazwy poszczegulnych obiektów
 */
class ItemNameProvider
{
public:
    /**
     * @brief Zwraca kolejną domyślną nazwę dla obiektu
     * @return QString
     */
    static QString getNextItemName();
private:
    static int nextItemNo;
};

#endif // ITEMNAMEPROVIDER_H
