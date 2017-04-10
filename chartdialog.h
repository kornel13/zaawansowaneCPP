#ifndef CHARTDIALOG_H
#define CHARTDIALOG_H

#include <QDialog>
#include <QtCharts/QChartView>
#include <QtCharts/QScatterSeries>
#include "Data/idataseries.h"

QT_CHARTS_USE_NAMESPACE

/**
 * @class ChartDialog
 * @brief Klasa definiująca obiekt okno dialogowego używanego do wyświetlania wykresu danych wyjściowych
 */
class ChartDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Konstruktor
     * @param parent Adres obiektu nadrzędnego
     */
    explicit ChartDialog(QWidget *parent = 0);

    /**
     * @brief Ustawia dane do wyświatlenia
     * @param data dane do wyświatlenia
     */
    void setResults(IDataSeries *data);

private:
    QChartView* view;
    QScatterSeries* series;
    QChart* chart;





};

#endif // CHARTDIALOG_H
