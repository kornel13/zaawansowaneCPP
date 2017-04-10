#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QPair>
#include "Common/itemconfig.h"

class QAction;
class QGraphicsLineItem;
class GraphicsItem;

/**
 * @enum SceneMode
 * @brief Odzwierciedla stan sceny i wplywa na zachowanie obsługi zdarzeń myszki
 */
enum SceneMode { MoveBlock, InsertConnection, InsertItem, ItemToAdd };

/**
 * @class Scene
 * @brief Odpowiada za główną scenę, na której umieszczone są graficzne reprezentację bloków arytmetycznych
 * Zmienia standardowe handlery obsługi zdarzeń myszy
 */
class Scene : public QGraphicsScene
{
    Q_OBJECT  
public:
    /**
     * @brief Konstruktor
     * @param parent Adres obiektunadrzędnego sceny
     */
    Scene(QObject *parent = 0);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent) override;

private:
    SceneMode mode;
    QGraphicsLineItem *currentLine;
    QPair<bool, ItemConfig> currentConfig;

    void filterBlockItems(QList<QGraphicsItem *> &list);

signals:
    /**
     * @brief Sygnał informujący obiekty nasłuchujące o umieszczeniu bloku na scenie
     * @param position Pozycja środka umieszczonego obiektu
     * @param config Konfiguracja umieszczonego obiektu
     */
    void itemInserted(QPointF position, ItemConfig config);

    /**
     * @brief Sygnał informujący o dodaniu nowego połączenia pomiędzy blokami na scenie
     * @param start Adres bloku wejściowego
     * @param outId Identyfikator obieku wartości wyjściowej danego bloku wejściowego
     * @param end Adres bloku wyjściowego
     * @param inId Identyfikator obieku wartości wejściowej danego bloku wyjściowego
     */
    void connectionInserted(GraphicsItem* start, unsigned outId,
                            GraphicsItem* end, unsigned inId);

public slots:
    /**
     * @brief Slot aktualizujący stan sceny
     * @param mode Aktualny stan sceny
     */
    void modeChanged(SceneMode mode);

    /**
     * @brief Slot aktualizujący konfigurację bloku, który jest w trakcie dodawania
     * @param config konfigurację bloku
     */
    void appliedConfig(ItemConfig config);
};

#endif // SCENE_H
