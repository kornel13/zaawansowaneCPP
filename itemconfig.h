#ifndef ITEMCONFIG_H
#define ITEMCONFIG_H


#include <QMap>
#include <QList>
#include <QPair>
#include <QString>
#include <functional>

enum ConfigType { DataType, OtherType};
using ValuePair = QPair<QString, std::function<bool(QString)> >;
using ConfigMap = QMap<QString,  ValuePair>;

class ItemConfig
{
public:
    ItemConfig();
    void addValue(QString name, QString value, ConfigType type, QString validateRegexp = "");
    void setValue(QString name, QString value);
    QString getValue(QString name);

    bool validate(QString name, QString value);

    QList<QString> getKeys() { return map.keys(); }
    QString getClassName() { return className; }
    void setClassName(QString name) { this->className = name; }

private:
     ConfigMap map;
     QString className;

     std::function<bool(QString)> getValidator(ConfigType type, QString validateRegexp = "");


};

#endif // ITEMCONFIG_H
