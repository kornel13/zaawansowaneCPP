#ifndef ITEMNAMEPROVIDER_H
#define ITEMNAMEPROVIDER_H

#include <QString>

class ItemNameProvider
{
public:
    static QString getNextItemName();
private:
    static int nextItemNo;
};

#endif // ITEMNAMEPROVIDER_H
