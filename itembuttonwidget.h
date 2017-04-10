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

#include "Common/itemconfig.h"

/**
 * @class ItemButtonWidget
 * @brief Widget, który zawiera przyciski służace do tworzenia bloków danego typu
 * Umożliwia wyświatlenie prawidłowego okna dialogowego konfiguracji danego typu bloku arytmetycznego
 */
class ItemButtonWidget: public QWidget
{
    Q_OBJECT
public:
    /**
     * @brief Konstruktor
     * @param itemAttributesDialogHash Adres słownika haszującego, który jako klucz ma identyfikator fabryki obiektu,
     * a jako wartość obiekt okna dialogowego konfiguracji danego typu bloku arytmetycznego
     * @param parent Adres obiektu nadrzędnego
     */
    ItemButtonWidget(QHash<int, ItemAttributesDialog*> *itemAttributesDialogHash, QWidget *parent);
    /**
     * @brief Dodaje fabrykę bloków arytmetycznych
     * @param itemFactory fabryka bloków arytmetycznych
     */
    void addItemFactory(ItemFactory *itemFactory);
    /**
     * @brief Getter grupy przycisków do tworzenia bloków arytmetycznych
     * @return QButtonGroup
     */
    QButtonGroup* getButtonGroup();

public slots:
    /**
     * @brief Wyświetla odpowiednie okno dialogowe konfiguracji bloku
     * @param id Identyfikator odpowiedniego okna dialogowego
     */
    void showOptions(int id);
    /**
     * @brief Slot ustawia stan aktywacji przycisku z mozliwoscią dodania bloku wyjściowego
     * @param enable Stan aktywacji przycisku wyjściowego
     */
    void enableOutput(bool enable);

signals:
    /**
     * @brief Sygnał wysyłany po pomyślnym wypełnieniu i zatwierdzeniu okna dialogowego konfiguracji
     * nowotworzonego bloku
     * @param id Identyfikator odpowiedniej fabryki wybranego bloku
     * @param config Konfiguracja bloku odebrana z okna dialogowego
     */
    void itemToAdd(int id, ItemConfig config);

private:
    QButtonGroup* buttonGroup;
    QVBoxLayout *layout;
    QHash<int, ItemAttributesDialog*> *itemAttributesDialogHash;
    QList<QToolButton*> outputButtons;

    void setSignalSlots();
};

#endif // ITEMBUTTONGROUP_H
