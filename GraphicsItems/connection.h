#ifndef CONNECTION_H
#define CONNECTION_H

#include <QGraphicsLineItem>
#include <QPolygon>
#include <memory>

class OutputElement;
class InputElement;

/**
 * @class Connection
 * @brief Definuje graficzny element połączenią pomiędzy blokami. Przeładowuje rysowanie obiektu na scenie
 */
class Connection : public QGraphicsLineItem
{
public /*enumarations*/:
    /**
     * @enum Okresla identyfikator typu tej klasy pochodnej QGraphicsItem
     */
    enum { Type = UserType + 11 };

public:
    /**
     * @brief Kostruktor
     *
     * @param _start Adres początkowego obiektu sygnału wyjściowego - początek linii
     * @param _finish Adres końcowego obiektu sygnału wejściowego - koniec linii
     */
    Connection(std::shared_ptr<OutputElement> _start, std::shared_ptr<InputElement> _finish);

    /**
     * @brief Przaładowanie funkcji z QGraphicsLineItem. Określa obiekt graficznej reprezentacji prostokąta otaczający obiekt na scenie
     * @return QRectF
     */
    QRectF boundingRect() const override;

    /**
     * @brief Aktualizuje współrzędne obiektu bazując na aktualnym polożeniu obiektów sygnału wejściowego i wyjściowego
     */
    void updatePosition();

    /**
     * @brief Usuwa referencję do swojego obiektu w obiektach sygnału wejściowego i wyjściowego
     */
    void removeItselfFromItems();

    /**
     * @brief Getter typu
     * @return int
     */
    int type() const override { return Type; }

    /**
     * @brief Getter obiektu sygnału wyjściowego - początku linii
     * @return OutputElement
     */
    OutputElement* getStart() { return start; }

    /**
     * @brief obiektu sygnału wejściowego - końca linii
     * @return InputElement
     */
    InputElement* getFinish() { return finish; }

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) override;

private:
    OutputElement *start;
    InputElement *finish;
    QPolygonF arrow;

};

#endif // CONNECTION_H
