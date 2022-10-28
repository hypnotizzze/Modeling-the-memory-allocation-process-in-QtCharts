#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  ui->table_1->setColumnCount(4);
  ui->table_2->setColumnCount(3);
  ui->table_3->setColumnCount(3);
  time_0.start();
  times = new QVector<int>;
  states = new QVector<int>;
  st = new QVector<int>;
  tm = new QVector<int>;
  QStringList header_1, header_2, header_3;
  header_1 << "Имя" << "Размер" << "До начала" << "Осталось";
  header_2 << "Имя" << "Размер" << "Заданное время";
  header_3 << "Имя" << "Размер" << "Время";
  ui->table_1->setHorizontalHeaderLabels(header_1);
  ui->table_2->setHorizontalHeaderLabels(header_2);
  ui->table_3->setHorizontalHeaderLabels(header_3);
  head = ui->table_1->horizontalHeader();
  head->setSectionResizeMode(0, QHeaderView::Stretch);
  head->setSectionResizeMode(1, QHeaderView::ResizeToContents);
  head = ui->table_2->horizontalHeader();
  head->setSectionResizeMode(0, QHeaderView::Stretch);
  head->setSectionResizeMode(1, QHeaderView::Stretch);
  head->setSectionResizeMode(2, QHeaderView::Stretch);
  head = ui->table_3->horizontalHeader();
  head->setSectionResizeMode(0, QHeaderView::Stretch);
  head->setSectionResizeMode(1, QHeaderView::Stretch);
  head->setSectionResizeMode(2, QHeaderView::Stretch);
  timer_0.setInterval(1000);
  connect(&timer_0, SIGNAL(timeout()), this, SLOT(updateTime()));
  timer_0.start();
  ui->prog_size->setMaximum(20);
  ui->prog_size->setMinimum(1);
  ui->proc_size->setMaximum(1000);
  ui->proc_size->setMinimum(1);
  ui->duration->setMinimum(1);
  tmp_data.name = "";
  tmp_data.size = tmp_data.duration = tmp_data.time_before_start = last = counter = 0;
  w1 = new widg_1;
}

MainWindow::~MainWindow()
{
  delete w1;
  delete times;
  delete states;
  delete head;
  delete ui;
}

void MainWindow::on_prog_size_valueChanged(int arg1)
{
  allocator.resize(arg1 * 8);  
}

void MainWindow::updateTime() {
  QString str;
  int value_1, value_2;
  ui->byte_array->setText(allocator.current_status());
  ui->byte_array->setAlignment(Qt::AlignCenter);
  for(auto i = 0; i < ui->table_1->rowCount(); i++) {
    str = ui->table_1->item(i, 2)->text();
    value_1 = str.toInt();
    str = ui->table_1->item(i, 3)->text();
    value_2 = str.toInt();
    if(value_1 > 0) {
      value_1--;
      ui->table_1->item(i, 2)->setText(QString::number(value_1));
    }
    else if(value_2 > 0) {
      value_2--;
      ui->table_1->item(i, 3)->setText(QString::number(value_2));
    }
    else {
     ui->table_1->removeRow(i);
     allocator.remove_proc(data[i].beg_of_memory, data[i].size * 8);
     QTableWidgetItem *item_0 = new QTableWidgetItem;
     QTableWidgetItem *item_1 = new QTableWidgetItem;
     QTableWidgetItem *item_2 = new QTableWidgetItem;
     int rows_3 = ui->table_3->rowCount();
     ui->table_3->insertRow(rows_3);
     item_0->setText(data[i].name);
     ui->table_3->setItem(rows_3, 0, item_0);
     item_1->setText(QString::number(data[i].size));
     ui->table_3->setItem(rows_3, 1, item_1);
     item_2->setText(QString::number(data[i].duration));
     ui->table_3->setItem(rows_3, 2, item_2);
     data.removeAt(i);
     last = time_0.elapsed();
     times->push_back(last);
     states->push_back(3);
     tm->push_back(last);
     st->push_back(data.count());
     counter++;
     qDebug() << data.count();     
    }
  }
  int size_0 = times->size();
  w1->update(times, states, size_0, tm, st, counter, data.count(), time_0.elapsed());
}

void MainWindow::on_add_button_clicked()
{
  QTableWidgetItem *item_0 = new QTableWidgetItem;
  QTableWidgetItem *item_1 = new QTableWidgetItem;
  QTableWidgetItem *item_2 = new QTableWidgetItem;
  int rows_1 = ui->table_1->rowCount();
  int rows_2 = ui->table_2->rowCount();
  if(tmp_data.size != 0 && tmp_data.name != "" && tmp_data.duration != 0) {
    tmp_data.beg_of_memory = allocator.add_proc(tmp_data.size * 8);
    if(tmp_data.beg_of_memory >= 0) {
        QTableWidgetItem *item_3 = new QTableWidgetItem;
        ui->table_1->insertRow(rows_1);
        item_0->setText(tmp_data.name);
        ui->table_1->setItem(rows_1, 0, item_0);
        item_1->setText(QString::number(tmp_data.size));
        ui->table_1->setItem(rows_1, 1, item_1);
        item_2->setText(QString::number(tmp_data.time_before_start));
        ui->table_1->setItem(rows_1, 2, item_2);
        item_3->setText(QString::number(tmp_data.duration));
        ui->table_1->setItem(rows_1, 3, item_3);
        data.append(tmp_data);
        last = time_0.elapsed();
        times->push_back(last);
        states->push_back(1);
        tm->push_back(last);
        st->push_back(data.count());
        counter++;
        qDebug() << data.count();
    }
    else if (tmp_data.beg_of_memory < 0) {
      ui->table_2->insertRow(rows_2);
      item_0->setText(tmp_data.name);
      ui->table_2->setItem(rows_2, 0, item_0);
      item_1->setText(QString::number(tmp_data.size));
      ui->table_2->setItem(rows_2, 1, item_1);
      item_2->setText(QString::number(tmp_data.duration));
      ui->table_2->setItem(rows_2, 2, item_2);
      last = time_0.elapsed();
      times->push_back(last);
      states->push_back(2);
    }
  }
}

void MainWindow::on_proc_name_editingFinished()
{
    tmp_data.name = ui->proc_name->text();
}


void MainWindow::on_proc_size_editingFinished()
{
    tmp_data.size = ui->proc_size->value();
}

void MainWindow::on_start_time_valueChanged(int arg1)
{
    tmp_data.time_before_start = arg1;
}

void MainWindow::on_duration_valueChanged(int arg1)
{
    tmp_data.duration = arg1;
}

void MainWindow::on_pushButton_clicked()
{
  w1->show();
}
