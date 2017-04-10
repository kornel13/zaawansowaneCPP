#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QPointF>
#include <QHash>

#include  "Expressions/iexpression.h"
#include "scene.h"
#include "Common/itemconfig.h"
#include "itemattributesdialog.h"
#include "chartdialog.h"

class ItemFactory;
class QActionGroup;

/**
 * @class Controller
 * @brief Klasa odpowiadające a główną logikę aplikacji. Zarządza fabrykami bloków arytmetycznych,
 * odpowiada za dodawanie obiektów do sceny, jak również budowanai drzewa wyrażeń,
 * koordynuje spójność modelu graficznego z modelem logicznym, bezpośredio wywołuje obliczenia i
 * notyfikuje o wynikach inne komponenty
 */
class Controller: public QObject
{
    Q_OBJECT
public:
    /**
     * @brief Konstruktor
     *
     * @param scene Adres głównej sceny aplikacji
     * @param chartDialog Adres obiektu, który wyświatla wykras danych wyjściowych
     * @param parent Adres obiektu nadrzędnego
     */
    Controller(Scene *scene, ChartDialog *chartDialog, QObject *parent = nullptr);

    /**
     * @brief Getter listy fabryk bloków arytmetycznych
     * @return QList<ItemFactory *>
     */
    QList<ItemFactory*> getItemFactory();

    /**
     * @brief Getter słownika haszującego, który jako klucz ma identyfikator fabryki obiektu,
     * a jako wartość obiekt okna dialogowego konfiguracji danego typu bloku arytmetycznego
     * @return QHash<int, ItemAttributesDialog *>
     */
    QHash<int, ItemAttributesDialog *> *getItemAttributesDialogs();

signals:
    /**
     * @brief Notyfikacja o zmianie stau sceny
     * @param mode stan sceny
     */
    void sceneModeChanged(SceneMode mode);

    /**
     * @brief Sygnał z tekstem do wyświatlenia
     * @param QString Przekazany teskt
     */
    void setOutputText(QString);

    /**
     * @brief Notyfikacja o odebranej konfiguracji bloku, który jest w trakcie tworzenia
     * @param ItemConfig Konfiguracja bloku, który jest w trakcie tworzenia
     */
    void appliedConfig(ItemConfig);

    /**
     * @brief Notyfikacja o stanie aktywacji bloków wyjściowych
     * @param enable Stan aktywacji bloków wyjściowych
     */
    void enableOutput(bool enable);

    /**
     * @brief Notyfikacja o stanie aktywacji akcji wyświetlającej wykres
     * @param enable stan aktywacji akcji wyświetlającej wykres
     */
    void enableChart(bool enable);

public slots:
    /**
     * @brief Slot obsugujący wybraną akcję stany sceny
     * @param action Adres akcji
     */
    void actionChanged(QAction* action);

    /**
     * @brief Slot notyfikujący o pomyślnym wypełnieniu i zatwierdzeniu okna dialogowego konfiguracji
     * nowotworzonego bloku
     * @param id Identyfikator odpowiedniej fabryki wybranego bloku
     * @param config Konfiguracja bloku odebrana z okna dialogowego
     */
    void itemToAdd(int id, ItemConfig config);

    /**
     * @brief Slot obsługujący notyfikację o umieszczeniu bloku na scenie
     * @param position Pozycja środka umieszczonego obiektu
     * @param config Konfiguracja umieszczonego obiektu
     */
    void itemInserted(QPointF position, ItemConfig config);

    /**
     * @brief Slot obsługujący notyfikację o załoszeniu żądania usunięcia bloku
     */
    void itemToDelete();

    /**
     * @brief Slot obsługujący notyfikację o załoszeniu żądania wykonanie obliczeń
     * @param bool
     */
    void  calculate(bool);

    /**
     * @brief Slot obsługujący notyfikację o dodaniu nowego połączenia pomiędzy blokami na scenie
     * @param start Adres bloku wejściowego
     * @param outId Identyfikator obieku wartości wyjściowej danego bloku wejściowego
     * @param end Adres bloku wyjściowego
     * @param inId Identyfikator obieku wartości wejściowej danego bloku wyjściowego
     */
    void connectionInserted(GraphicsItem *start, unsigned outId,
                            GraphicsItem *end, unsigned inId);

private:
    void addItemFactory(ItemFactory* itemFactory);

    Scene *scene;
    ChartDialog *chartDialog;
    QActionGroup *actionGroup;
    QList<ItemFactory*> itemFactoryList;
    QHash<int, ItemAttributesDialog*> itemAttributesDialogHash;
    ItemFactory* selectedItemFactory;
    IExpression* outputExpression;
};

#endif // CONTROLLER_H
