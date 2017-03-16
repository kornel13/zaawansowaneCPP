#ifndef ITEM_H
#define ITEM_H

#include <QMap>
#include <QList>
#include <QIcon>
#include <QString>
#include <QObject>
#include <QPair>

class IExpression;
class GraphicsItem;

using Item = QPair<GraphicsItem*, IExpression*>;

class ItemFactory : public QObject
{
public:
    ItemFactory(QString name, int id, QObject *parent = nullptr);
    virtual Item createItemObject(QMap<QString, QString> config) = 0;

    int getId();
    QIcon getIcon();
    QString getName();

protected:
    void setIcon(QIcon& icon);

private:
    void AddCommonAttributes();

    QList<QString> attributes;
    QIcon icon;
    QString name;
    int id;





};

#endif // ITEM_H
