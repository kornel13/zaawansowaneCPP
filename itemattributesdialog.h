#ifndef ITEMATTRIBUTESDIALOG_H
#define ITEMATTRIBUTESDIALOG_H

#include <QDialog>
#include <QMap>
#include <QString>
#include "Common/itemconfig.h"

class QLineEdit;
class QVBoxLayout;

/**
 * @class ItemAttributesDialog
 * @brief Klasa definiująca obiekty okna dialogowego konfiguracji danego typu bloku arytmetycznego.
 * Obiektu tej klasy wykorzystwany jest od odczytu konfiguracji danego bloku
 */
class ItemAttributesDialog : public QDialog
{
    Q_OBJECT
public:
    /**
     * @brief Konstruktor
     * @param defaultConfig Domyslana konfiguracja
     * @param parent Adres obiektu nadrzędnego
     */
    ItemAttributesDialog(ItemConfig defaultConfig, QWidget *parent);
    /**
     * @brief Getter domyślnych ustawień
     * @return ItemConfig
     */
    ItemConfig getDefaultConfig();
    /**
     * @brief Getter wprowadzonyhc ustawień
     * @return ItemConfig
     */
    ItemConfig getConfig();
private:
    ItemConfig defaultConfig;
    QMap<QString, QLineEdit*> inputMap;

    bool validate();
    void addAttributes(QVBoxLayout *layout);

public slots:
    /**
     * @brief Przperowadza walidacje wprowadzonych danych,
     * a gdy dane, zostału wprowadzone prawidłowo ustawia kod wyniku jako Accepted
     */
    void buttonClicked();

};

#endif // ITEMATTRIBUTESDIALOG_H
