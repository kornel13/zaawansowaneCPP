#ifndef ITEMBUTTONGROUP_H
#define ITEMBUTTONGROUP_H

#include <QWidget>

class QButtonGroup;
class ItemFactory;
class QVBoxLayout;

class ItemButtonWidget: public QWidget
{
public:
    ItemButtonWidget(QWidget *parent);
    void addItemFactory(ItemFactory *itemFactory);
    QButtonGroup* getButtonGroup();

private:
    QButtonGroup* buttonGroup;
    QVBoxLayout *layout;
};

#endif // ITEMBUTTONGROUP_H
