#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "chartdialog.h"

class QActionGroup;

namespace Ui {
class MainWindow;
}

class Scene;
class Controller;
class ItemButtonWidget;
class ItemAttributesDialog;

/**
 * @class MainWindow
 * @brief Klasa głównego okna aplikacji. MainWindow tworzy wszystkie obiekty najwyższego poziomu obłujących
 * główne elementy GUI i logikę aplikacji. Jest najwyższym rodzicem dla obiektów dziedziczących po QObject.
 * Łączy główne sygnały ze slotami w aplikaci.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Konstruktor
     * @param parent Adres obiektu nadrzędnego
     */
    explicit MainWindow(QWidget *parent = 0);
    /**
     * @brief Destruktor
     */
    ~MainWindow();

public slots:
    /**
     * @brief Slot obługujący sygnal o tym czy obiekt został zaznaczony na scenie
     * W zależności od stanu aktywuję, bądź dezatwuje akcje kasowania obiektu
     */
    void sceneSelectionChanged();
    /**
     * @brief Slot ustawia akcje "Move" jako zaznaczoną
     */
    void changeModeToMove();

private:
    Ui::MainWindow *ui;
    Scene *scene;
    Controller *controller;
    ItemButtonWidget *itemButtonWidget;
    QActionGroup *actionGroup;

    ChartDialog* chartDialog;


    void setSignalsSlots();
};

#endif // MAINWINDOW_H
