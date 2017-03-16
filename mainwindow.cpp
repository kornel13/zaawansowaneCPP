#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QActionGroup>
#include <QAction>

#include "scene.h"
#include "controller.h"
#include "itembuttonwidget.h"
#include "mapper.h"

#include <QDebug>
#include "itemfactory.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new Scene(this);

    ui->graphicsView->setScene(scene);
    scene->setSceneRect(0,0,ui->graphicsView->width(),ui->graphicsView->height());

    ui->centralWidget->setMouseTracking(true);
    //ui->widget->setMouseTracking(true);

    QAction* ghostAction = new QAction(this);
    ghostAction->setVisible(false);

    actionGroup = new QActionGroup(this);
    actionGroup->addAction(ui->actionAddLine);
    actionGroup->addAction(ui->actionMove);
    actionGroup->addAction(ghostAction);
    actionGroup->setExclusive(true);

    Mapper::actionToEnumMap[ui->actionAddLine] = Insert;
    Mapper::actionToEnumMap[ui->actionMove] = Move;

    controller = new Controller(scene, this);
    itemButtonWidget = new ItemButtonWidget(this);

    ItemFactory* f = nullptr;
    foreach (f, controller->getItemFactory()) {
        itemButtonWidget->addItemFactory(f);
    }

    QVBoxLayout *groupBoxLayout = new QVBoxLayout();
    groupBoxLayout->addWidget(itemButtonWidget);
    ui->groupBox->setLayout(groupBoxLayout);

    setSignalsSlots();

}

void MainWindow::setSignalsSlots()
{
    connect(actionGroup, SIGNAL(triggered(QAction*)),
            controller, SLOT(actionChanged(QAction*)));

    connect(itemButtonWidget->getButtonGroup(), SIGNAL(buttonClicked(int)),
            controller, SLOT(buttonChanged(int)));

    connect(controller, SIGNAL(sceneModeChanged(SceneMode)),
            scene, SLOT(modeChanged(SceneMode)));

    connect(scene, SIGNAL(itemInserted(QPointF)),
            controller, SLOT(itemInserted(QPointF)));


}

MainWindow::~MainWindow()
{
    delete ui;
}
