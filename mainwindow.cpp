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
#include "itemconfig.h"

#include "itemattributesdialog.h"

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
    itemButtonWidget = new ItemButtonWidget(controller->getItemAttributesDialogs(), this);

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

    connect(itemButtonWidget, SIGNAL(itemToAdd(int, ItemConfig)),
            controller, SLOT(itemToAdd(int, ItemConfig)));

    connect(controller, SIGNAL(sceneModeChanged(SceneMode)),
            scene, SLOT(modeChanged(SceneMode)));

    connect(controller, SIGNAL(appliedConfig(ItemConfig)),
            scene, SLOT(appliedConfig(ItemConfig)));

    connect(scene, SIGNAL(itemInserted(QPointF, ItemConfig)),
            controller, SLOT(itemInserted(QPointF, ItemConfig)));

    connect(scene, SIGNAL(connectionInserted(GraphicsItem*,uint,GraphicsItem*,uint)),
            controller, SLOT(connectionInserted(GraphicsItem*,uint,GraphicsItem*,uint))) ;

    connect(ui->actionRun, SIGNAL(triggered(bool)),
            controller, SLOT(calculate(bool)));

    connect(controller, SIGNAL(setOutputText(QString)),
            ui->textBrowser, SLOT(append(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}
