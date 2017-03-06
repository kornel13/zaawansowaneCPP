#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QActionGroup>
#include <QAction>

#include "scene.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new Scene(this);

    ui->graphicsView->setScene(scene);
    ui->centralWidget->setMouseTracking(true);
    //ui->widget->setMouseTracking(true);

    actionGroup = new QActionGroup(this);
    actionGroup->addAction(ui->actionAddLine);
    actionGroup->addAction(ui->actionMove);
    actionGroup->setExclusive(true);

    setSignalsSlots();

}

void MainWindow::setSignalsSlots()
{
    connect(actionGroup, SIGNAL(triggered(QAction*)),
            scene, SLOT(modeChanged(QAction*)));
}

MainWindow::~MainWindow()
{
    delete ui;
}
