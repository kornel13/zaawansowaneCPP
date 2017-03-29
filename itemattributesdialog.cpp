#include "itemattributesdialog.h"

#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>
#include <QPalette>
#include <QLineEdit>

ItemAttributesDialog::ItemAttributesDialog(ItemConfig defaultConfig, QWidget *parent)
    : QDialog(parent), defaultConfig(defaultConfig)
{
    setWindowTitle(defaultConfig.getClassName());

    QVBoxLayout* layout = new QVBoxLayout();

    addAttributes(layout);
    QPushButton* createButton = new QPushButton("CREATE",this);
    layout->addWidget(createButton);

    setLayout(layout);

    connect(createButton, SIGNAL(clicked(bool)),
            this, SLOT(buttonClicked()));
}

void ItemAttributesDialog::buttonClicked()
{
    if(validate()) accept();
}

void ItemAttributesDialog::addAttributes(QVBoxLayout* layout)
{
    QString key;
    foreach(key, defaultConfig.getKeys())
    {
        QLabel *label = new QLabel(key, this);
        QLineEdit *lineEdit = new QLineEdit(this);
        label->setBuddy(lineEdit);

        lineEdit->setText(defaultConfig.getValue(key));
        inputMap[key] = lineEdit;
        layout->addWidget(label);
        layout->addWidget(lineEdit);
    }
}

ItemConfig ItemAttributesDialog::getDefaultConfig()
{
    return defaultConfig;
}

ItemConfig ItemAttributesDialog::getConfig()
{
    ItemConfig config = defaultConfig;
    QString key;
    foreach(key, defaultConfig.getKeys())
    {
        config.setValue(key, inputMap[key]->text());
    }
    return config;
}

bool ItemAttributesDialog::validate()
{
    bool result = true;
    QString key;
    foreach(key, defaultConfig.getKeys())
    {
        auto text = inputMap[key]->text();
        if( ! defaultConfig.validate(key,text) )
        {
            QPalette palette;
            palette.setColor(QPalette::Base,Qt::red);
            inputMap[key]->setPalette(palette);

            result = false;
            break;
        }
    }

    return result;
}

