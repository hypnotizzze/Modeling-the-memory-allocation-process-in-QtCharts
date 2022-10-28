#ifndef BYTE_ALLOCATOR_H
#define BYTE_ALLOCATOR_H
#include <QTime>
#include <QString>
#include <QVector>
#include <QVariant>
#include <QDebug>

struct data_sector {
    QString name;
    int size, time_before_start, duration, beg_of_memory; 
};

class byte_allocator {
  private:
    QVector<int> memory;
    int prog_size;
  public:
    byte_allocator();
    ~byte_allocator();
    void resize(int);
    int add_proc(int);
    QString current_status();
    void remove_proc(int, int);
};

#endif // BYTE_ALLOCATOR_H
