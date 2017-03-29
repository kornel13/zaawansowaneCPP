#ifndef ITEMATTRIBUTESDIALOG_H
#define ITEMATTRIBUTESDIALOG_H

#include <QDialog>
#include <QMap>
#include <QString>
#include "itemconfig.h"

class QLineEdit;
class QVBoxLayout;

class ItemAttributesDialog : public QDialog
{
    Q_OBJECT
public:
    ItemAttributesDialog(ItemConfig defaultConfig, QWidget *parent);
    ItemConfig getDefaultConfig();
    ItemConfig getConfig();
private:
    ItemConfig defaultConfig;
    QMap<QString, QLineEdit*> inputMap;

    bool validate();
    void addAttributes(QVBoxLayout *layout);

public slots:
    void buttonClicked();

};

#endif // ITEMATTRIBUTESDIALOG_H
