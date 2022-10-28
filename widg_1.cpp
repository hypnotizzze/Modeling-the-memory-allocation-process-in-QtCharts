#include "widg_1.h"

using namespace QtCharts;

widg_1::widg_1(QWidget *parent) : QWidget(parent), ui(new Ui::Form) {
  ui->setupUi(this);
  curr_size_0 = curr_size_1 = max_y = 0;
  x_0 = new QValueAxis();
  y_0 = new QValueAxis();
  x_1 = new QValueAxis();
  y_1 = new QValueAxis();
  series_0 = new QLineSeries(this);
  chart_0 = new QChart();
  view_0 = new QChartView(chart_0);
  series_1 = new QLineSeries(this);
  chart_1 = new QChart();
  view_1 = new QChartView(chart_1);

  y_0->setRange(0, 3);  // 0
  y_0->setTickCount(4);
  x_0->setTickCount(6);
  x_0->setTitleText("t, мс");
  x_0->setLabelFormat("%i");
  y_0->setTitleText("1 - active, 2 - no memory, 3 - ended");
  y_0->setLabelFormat("%i");
  chart_0->addSeries(series_0);
  chart_0->legend()->hide();
  chart_0->setTitle("1");
  chart_0->addAxis(x_0, Qt::AlignBottom);
  chart_0->addAxis(y_0, Qt::AlignLeft);
  series_0->attachAxis(x_0);
  series_0->attachAxis(y_0);
  view_0->setRenderHint((QPainter::Antialiasing));
  ui->horizontalLayout->addWidget(view_0);

  y_1->setTickCount(6);
  x_1->setTitleText("t, мс");
  x_1->setLabelFormat("%g");
  y_1->setTitleText("Активные процессы, кол-во");
  y_1->setLabelFormat("%i");
  chart_1->addSeries(series_1); // 1
  chart_1->legend()->hide();
  chart_1->setTitle("2");
  chart_1->addAxis(x_1, Qt::AlignBottom);
  chart_1->addAxis(y_1, Qt::AlignLeft);
  series_1->attachAxis(x_1);
  series_1->attachAxis(y_1);
  view_1->setRenderHint((QPainter::Antialiasing));
  ui->horizontalLayout->addWidget(view_1);
}

widg_1::~widg_1() {
  delete series_0;
  delete chart_0;
  delete view_0;
  delete series_1;
  delete chart_1;
  delete view_1;
}

void widg_1::update(QVector<int> *x, QVector<int> *y, int size_0, QVector<int> *x1, QVector<int>* y1, int size_1, int max, int max_t) {
  for(auto i = curr_size_0; i < size_0; i++) {
    series_0->append(x->at(i), y->at(i));
  }
  x_0->setRange(0, max_t);  
  chart_0->update();
  curr_size_0 = size_0;  
  for(auto i = curr_size_1; i < size_1; i++) {
    series_1->append(x1->at(i), y1->at(i));
  }
  if(max_y < max)
    max_y = max;
  x_1->setRange(0, max_t);
  y_1->setRange(0, max_y);
  chart_1->update();
  curr_size_1 = size_1;  
}
