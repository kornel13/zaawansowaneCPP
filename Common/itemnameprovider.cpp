#include "itemnameprovider.h"

#include <sstream>
#include <string>

int ItemNameProvider::nextItemNo = 1;

QString ItemNameProvider::getNextItemName()
{
    std::stringstream ss;
    std::string tmp;
    ss << "Item_no_"<< nextItemNo++;
    ss >> tmp;
    QString qtmp;
    return  qtmp.fromStdString(tmp);
}




