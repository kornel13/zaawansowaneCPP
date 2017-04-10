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

    chart = new QChart();
    view->setChart(chart);

    series = new QScatterSeries();

    setLayout(layout);

}


void ChartDialog::setResults(IDataSeries *data)
{
    series->clear();
    chart->removeAllSeries();

    auto dataSeries = data->getList();
    float index = 0.0f;
    for(auto value: dataSeries)
    {
        series->append(index, value);
        index = index + 1.0f;
    }
   chart->addSeries(series);

   chart->legend()->hide();
   chart->createDefaultAxes();
   chart->setTitle("Outup chart");

   view->setRenderHint(QPainter::Antialiasing);


}
