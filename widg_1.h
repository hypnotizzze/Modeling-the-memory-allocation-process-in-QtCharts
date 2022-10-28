#ifndef WIDG_1_H
#define WIDG_1_H

#include <QWidget>
#include <QtCharts/QChart>
#include <QtCharts/QLineSeries>
#include <QtCharts/QChartView>
#include <QPainter>
#include <QHBoxLayout>
#include <QTimer>
#include <QValueAxis>
#include "ui_form.h"

using namespace QtCharts;

namespace Ui {
class Form;
}

class widg_1 : public QWidget
{
    Q_OBJECT
    
  public:
    explicit widg_1(QWidget *parent = nullptr);
    void update(QVector<int>*, QVector<int>*, int, QVector<int>*, QVector<int>*, int, int, int);
    ~widg_1();
    
  private:
    int curr_size_0, curr_size_1, max_y;
    Ui::Form *ui;
    QHBoxLayout *layout_0;
    QLineSeries *series_0, *series_1;
    QChart *chart_0, *chart_1;
    QChartView *view_0, *view_1;
    QValueAxis *x_0, *x_1, *y_0, *y_1;    
    QTimer timer;
};
#endif // WIDG_1_H
