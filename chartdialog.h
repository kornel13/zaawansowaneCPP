#ifndef CHARTDIALOG_H
#define CHARTDIALOG_H

#include <QDialog>
#include <QtCharts/QChartView>
#include <QtCharts/QScatterSeries>

QT_CHARTS_USE_NAMESPACE

class ChartDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ChartDialog(QWidget *parent = 0);

private:
    QChartView* view;
    QScatterSeries* series;

    void setDummy();



};

#endif // CHARTDIALOG_H
