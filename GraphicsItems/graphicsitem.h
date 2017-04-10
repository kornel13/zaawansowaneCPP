#ifndef GRAPHICSITEM_H
#define GRAPHICSITEM_H

#include <QGraphicsItemGroup>
#include <QVector>
#include <memory>
#include <QString>

#include "GraphicsItems/inputelement.h"
#include "GraphicsItems/outputelement.h"

typedef QGraphicsSimpleTextItem Icon;

/**
 * @class GraphicsItem
 * @brief Określa graficzną reprezentację bloku. Określa wygląd bloku na scenie i zarządza połączeniami z innymi blokami
 */
class GraphicsItem : public QGraphicsItemGroup
{
public /*enumerations*/:
    /**
     * @enum Okresla identyfikator typu tej klasy pochodnej QGraphicsItem
     */
    enum { Type = UserType + 10 };

public:
    /**
     * @brief Kostruktor
     *
     * @param inputsNumber Liczna wejść - obiektów sygnału wejściowego
     * @param outputNumber Liczba wyjść - obiektów sygnału wyjściowego
     * @param className Nazwa klasy bloku
     * @param itemName Naze konkretnego obiekt ubloku
     * @param icon Ikona bloku
     */
    GraphicsItem(unsigned inputsNumber, unsigned outputNumber, QString className, QString itemName, QString icon);

    /**
     * @brief Funckcja sprawdza czy przekazane współrzędne punktu na scenie zawierają się
     * w którymkolwiek wejściu obiektu i czy to wejście nie ma już połączenia
     * @param point Punkt na scenie
     * @return int Index wejścia któe może być połączone, gdy wolne wyjście nie zostało wybrane funckja zwraca -1
     */
    int whichInputCanBeConnected(QPointF point);

    /**
     * @brief Funkcja która zwraca index wejścia na podstawie adresu obiektu Connection - graficznej reprezentacji połączenia
     * @param connection Adres obiektu Connection
     * @return int Index wejścia, gdy polaczenie nie jest powiazane z zedym z wejść funckja zwraca -1
     */
    int getInputIndex(Connection* connection);

    /**
     * @brief Funckcja sprawdza czy przekazane współrzędne punktu na scenie zawierają się
     * w wyjściu obiektu i czy to wyjście nie ma już połączenia
     * @param point Punkt na scenie
     * @return rezultat czy wyjście które może być połączone, gdy wolne wyjście nie zostało wybrane funckja zwraca -1
     */
    bool canOutputBeConnected(QPointF point);

    /**
     * @brief Usuwa przekazane połączenie, gdy dane połączenie nie jest związane z żadnym z wejść i wyjściem funkcjie nie ma żadych efektów
     * @param connection Adres połączenia do usunięcia
     */
    void removeConnection(Connection* connection);

    /**
     * @brief Usuwa wszystkie polączenia obiektu
     */
    void removeAllConnections();

    /**
     * @brief Zwraca wszystkie połączenia obiektu
     * @return QList<Connection *> lista połączeń
     */
    QList<Connection*> getAllConnections();

    /**
     * @brief Getter obiektu sygnału wyjściowego
     * @return std::shared_ptr<OutputElement>
     */
    std::shared_ptr<OutputElement> getOutput() const
    {
        return output;
    }

    /**
     * @brief Getter obiektu sygnału wejściowego
     * @param index indeks wejścia
     * @return std::shared_ptr<InputElement>
     */
    std::shared_ptr<InputElement> getInput(int index) const
    {
        if(index >= 0 && index < inputs.size() )
        {
            return inputs[index];
        }
        return nullptr;
    }

    /**
     * @brief Getter obiektu sygnału wyjściowego - początku linii
     * @return OutputElement
     */
    int type() const override { return Type; }

    /**
     * @brief Określa bazowy obiekt graficznej reprezentacji prostokąta otaczający obiekt na scenie
     * @return QRectF
     */
    QRectF getBaseRect() const;

private:
    QVector< std::shared_ptr<InputElement> > inputs;
    std::shared_ptr<OutputElement> output;
    std::shared_ptr<QGraphicsRectItem> base;

    std::shared_ptr<QGraphicsSimpleTextItem> className;
    std::shared_ptr<QGraphicsSimpleTextItem> itemName;
    std::shared_ptr<Icon> icon;

    void setBase();
    void setInputs(int number);
    void setOutput(int number);
    void setClassAndItemNames(QString className, QString itemName);
    void setIcon(QString itemString);
    void centerSubitem(std::shared_ptr<QGraphicsItem> item);
    void moveByY(std::shared_ptr<QGraphicsItem> item, qreal dy);


    static const qreal SIZE;


};

#endif // GRAPHICSITEM_H
