#include "itembuttonwidget.h"

#include <QToolButton>
#include <QVBoxLayout>
#include <QButtonGroup>
#include <QHash>

#include "Factories/itemfactory.h"
#include "itemattributesdialog.h"

ItemButtonWidget::ItemButtonWidget(QHash<int, ItemAttributesDialog *> *itemAttributesDialogHash, QWidget *parent)
    : itemAttributesDialogHash(itemAttributesDialogHash), QWidget(parent)
{
    buttonGroup = new QButtonGroup(this);
    buttonGroup->setExclusive(true);

    layout = new QVBoxLayout(this);
    setLayout(layout);

    setSignalSlots();
}

void ItemButtonWidget::addItemFactory(ItemFactory *itemFactory)
{
    QToolButton *button = new QToolButton(this);
    button->setText(itemFactory->getDefaultConfig().getClassName());
    button->setCheckable(false);
    if(itemFactory->isOutputFactory()) outputButtons.append(button);

    buttonGroup->addButton(button, itemFactory->getId());
    layout->addWidget(button);
}

QButtonGroup* ItemButtonWidget::getButtonGroup()
{
    return buttonGroup;
}

void ItemButtonWidget::setSignalSlots()
{
    connect(buttonGroup, SIGNAL(buttonClicked(int)),
            this, SLOT(showOptions(int)));
}

void ItemButtonWidget::showOptions(int id)
{
    if((*itemAttributesDialogHash)[id]->exec())
    {
        ItemConfig config = (*itemAttributesDialogHash)[id]->getConfig();
        emit itemToAdd(id, config);
    }
}

void ItemButtonWidget::enableOutput(bool enable)
{
    QToolButton* outputButton;
    foreach(outputButton, outputButtons)
        outputButton->setEnabled(enable);
}


