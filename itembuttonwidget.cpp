#include "itembuttonwidget.h"

#include <QToolButton>
#include <QVBoxLayout>
#include <QButtonGroup>

#include "itemfactory.h"

ItemButtonWidget::ItemButtonWidget(QWidget *parent)
    : QWidget(parent)
{
    buttonGroup = new QButtonGroup(this);
    buttonGroup->setExclusive(true);

    layout = new QVBoxLayout(this);
    setLayout(layout);
}

void ItemButtonWidget::addItemFactory(ItemFactory *itemFactory)
{
    QToolButton *button = new QToolButton(this);
    button->setText(itemFactory->getName());
    button->setCheckable(true);

    buttonGroup->addButton(button, itemFactory->getId());
    layout->addWidget(button);
}

QButtonGroup* ItemButtonWidget::getButtonGroup()
{
    return buttonGroup;
}
