#include "chartdialog.h"
#include <QVBoxLayout>


ChartDialog::ChartDialog(QWidget *parent) :
    QDialog(parent)
{
    resize(QSize(300,400));
    QVBoxLayout* layout = new QVBoxLayout();
    layout->setStretch(0,3);
    layout->setStretch(1,1);

    view = new QChartView(this);
    QWidget *buttonWidget = new QWidget(this);

    layout->addWidget(view);
    layout->addWidget(buttonWidget);

    setDummy();

    setLayout(layout);

}

void ChartDialog::setDummy()
{
        series = new QScatterSeries();

        series->append(0, 6);
        series->append(2, 4);
        series->append(3, 8);
        series->append(7, 4);
        series->append(10, 5);
        *series << QPointF(11, 1) << QPointF(13, 3) << QPointF(17, 6) << QPointF(18, 3) << QPointF(20, 2);

        QChart *chart = new QChart();
        chart->legend()->hide();
        chart->addSeries(series);
        chart->createDefaultAxes();
        chart->setTitle("Simple line chart example");

        view->setChart(chart);

}
