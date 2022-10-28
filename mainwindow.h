#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVariant>
#include <QStringList>
#include <QHeaderView>
#include <QTableWidgetItem>
#include <QDebug>
#include <QTimer>
#include <QList>
#include "byte_allocator.h"
#include "widg_1.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
  public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    
  private slots:   
    void updateTime();
    
    void on_prog_size_valueChanged(int arg1);
    
    void on_add_button_clicked();
    
    void on_proc_name_editingFinished();
    
    void on_proc_size_editingFinished();
    
    void on_start_time_valueChanged(int arg1);
    
    void on_duration_valueChanged(int arg1);    
    
    void on_pushButton_clicked();
    
  private:
    int last, counter;
    QVector<int> *states, *times, *st, *tm;
    QList<data_sector> data;
    data_sector tmp_data;
    Ui::MainWindow *ui;
    QHeaderView *head;
    QTime time_0;
    QTimer timer_0;
    byte_allocator allocator;
    widg_1 *w1;
};
#endif // MAINWINDOW_H
