#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QActionGroup;

namespace Ui {
class MainWindow;
}

class Scene;
class Controller;
class ItemButtonWidget;
class ItemAttributesDialog;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void sceneSelectionChanged();
    void changeModeToMove();

private:
    Ui::MainWindow *ui;
    Scene *scene;
    Controller *controller;
    ItemButtonWidget *itemButtonWidget;
    QActionGroup *actionGroup;

    void setSignalsSlots();
};

#endif // MAINWINDOW_H
