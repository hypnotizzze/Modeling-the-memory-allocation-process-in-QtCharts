#include "byte_allocator.h"

byte_allocator::byte_allocator() {
  prog_size = 0;
  memory.resize(0);
}

byte_allocator::~byte_allocator() {
  
}

void byte_allocator::resize(int size) {
  int tmp = prog_size;
  prog_size = size;
  memory.resize(prog_size);
  for(int i = tmp; i < prog_size; i++) {
    memory.append(0);
  }
}

int byte_allocator::add_proc(int size) {
  int free_cells = 0, flag = -1;
  if(size > prog_size)
    return flag;
  else for(auto i = 0; i < prog_size; i++) {
    if(memory[i] == 0)
      free_cells++;
    else
      free_cells = 0;
    if(free_cells == size) {
      flag = i - free_cells + 1;
      for(auto j = i - free_cells + 1; j < i - free_cells + 1 + size; j++)
        memory[j] = 1;
      return flag;
    }
  }
  return flag;
}

QString byte_allocator::current_status() {
  QString str = "";
  for(auto i=0; i < prog_size ; i++)
    str.append(QString::number(memory[i]));
  return str;
}

void byte_allocator::remove_proc(int start, int size) {
  for(auto i = start; i < start + size; i++) {
    memory[i] = 0;
  }
}
