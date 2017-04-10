#ifndef OUTPUTELEMENT_H
#define OUTPUTELEMENT_H

#include <QGraphicsPolygonItem>
#include <QPointF>
#include <QPolygonF>

class Connection;

/**
 * @class OutputElement
 * @brief Klasa tworząca graficzne obiekty sygnału wejściowego
 * @attention od autora: wiem ze klasa OutputElement i InputElement, niestety etap
 * projetu nie pozwalał na taką zmianę - wiązałoby się to z destabilizacją wielu komponentów
 * TO REFACTOR IN FUTURE
 */
class OutputElement : public QGraphicsPolygonItem
{
public:
    /**
     * @brief Kostruktor
     * @param center Centralne współrzędne obiektu
     * @param parent Adres obiektu nadrzędnego
     */
    OutputElement(QPointF center, QGraphicsItem *parent = nullptr);

    /**
     * @brief Dodaje połączenie do obiektu
     * @param connection Adres połączenia
     */
    void addConnection(Connection* connection);

    /**
     * @brief Usuwa połaczenie z obiektu
     * @param connection Adres połączenia
     */
    void removeConnection(Connection* connection);

    /**
     * @brief Zwraca czy obiekt ma przypisane połączenie
     * @return bool
     */
    bool isConnection() { return connection != nullptr; }

    /**
     * @brief Zwraca czy obiekt ma przypisane połączenie o porzekazanym adresie
     * @param checked Adres połaczenia
     * @return bool
     */
    bool isSpecificConnection(Connection *checked) { return connection == checked; }

    /**
     * @brief Zwraca pozycję obiektu
     * @return QPointF
     */
    QPointF getPosition();

    /**
     * @brief Zwraca wielokąt będący bazą graficznej reprezentacji obiektu na scenie
     * @return QPolygonF
     */
    QPolygonF getPolygon();

    /**
     * @brief Getter przypisanego połączenia
     * @return Connection
     */
    Connection* getConnection();

private:
    Connection *connection;
    static const qreal SIZE;
};

#endif // OUTPUTELEMENT_H
