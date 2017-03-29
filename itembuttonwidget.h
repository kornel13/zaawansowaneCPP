#ifndef ITEMBUTTONGROUP_H
#define ITEMBUTTONGROUP_H

#include <QWidget>
#include <QHash>
#include <QList>

class QButtonGroup;
class ItemFactory;
class QVBoxLayout;
class ItemAttributesDialog;
class QToolButton;

#include "itemconfig.h"

class ItemButtonWidget: public QWidget
{
    Q_OBJECT
public:
    ItemButtonWidget(QHash<int, ItemAttributesDialog*> *itemAttributesDialogHash, QWidget *parent);
    void addItemFactory(ItemFactory *itemFactory);
    QButtonGroup* getButtonGroup();

public slots:
    void showOptions(int id);
    void enableOutput(bool enable);

signals:
    void itemToAdd(int id, ItemConfig config);

private:
    QButtonGroup* buttonGroup;
    QVBoxLayout *layout;
    QHash<int, ItemAttributesDialog*> *itemAttributesDialogHash;
    QList<QToolButton*> outputButtons;

    void setSignalSlots();
};

#endif // ITEMBUTTONGROUP_H
