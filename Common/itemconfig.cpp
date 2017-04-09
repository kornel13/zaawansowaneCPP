#include "Common/itemconfig.h"
#include "Data/genericData.h"

#include <QRegExp>

ItemConfig::ItemConfig()
{

}

void ItemConfig::addValue(QString name, QString value, ConfigType type, QString validateRegexp)
{
    map[name] = ValuePair(value, getValidator(type, validateRegexp));
}

void ItemConfig::setValue(QString name, QString value)
{
    map[name].first = value;
}

QString ItemConfig::getValue(QString name)
{
    return map[name].first;
}

bool ItemConfig::validate(QString name, QString value)
{
    return map[name].second(value);
}

std::function<bool(QString)> ItemConfig::getValidator(ConfigType type, QString validateRegexp )
{
    std::function<bool(QString)> validator;

    if(OtherType == type)
    {
        if("" != validateRegexp)
        {
           validator = [validateRegexp](QString value)->bool
           {
               QRegExp regexp(validateRegexp);
               return regexp.exactMatch(value);
           };

        }else
        {
          validator = [validateRegexp](QString value)->bool {return true;};
        }

    }else
    {
        validator = [validateRegexp](QString value)->bool
        {
            Data tmp(0);
            return tmp.fromString(value);
        };
    }

    return validator;
}


