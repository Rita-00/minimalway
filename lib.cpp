#include "lib.h"
#include <fstream>

int read_file(std::ifstream &file, int a[SIZE][SIZE],std::string ver[SIZE]) {
  if (file.is_open()) {
    std::string startver, endver;
    int i, j, k, length;

    while (!file.eof()) {
      file >> startver >> endver >> length;
      if (ver[0] == " ") {
        ver[0] = startver;
        ver[1] = endver;
        k = 2;
        i = 0;
        j = 1;
      } else {
        i = 0;
        j = 0;
        for (int t = 0; t < k; t++) {
          if (ver[t] == startver) {
            i = t;
          }
          {
            if (ver[t] == endver) {
              j = t;
            }
          }
        }
        if ((i == 0) && (j == 0) && (ver[0] != startver) && (ver[0] != endver)) {
          i = k;
          ver[i]=startver;
          j = k + 1;
          ver[j]=endver;
          k = k + 2;
        }
        if (((i == 0) || (j == 0)) && ((ver[0] != startver) || (ver[0] != endver))) {
            if ((j == 0)||(ver[0] != startver)||(ver[0] != endver)) {
              ver[k] = endver;
              j = k;
              k++;
            } else {
              if ((i == 0) || (ver[0] != startver) || (ver[0] != endver)) {
                ver[k] = startver;
                i = k;
                k++;
              }
            }
        }
      }
      a[i][j] = length;
      a[j][i] = length;
    }
  }
}

int minway(int a[SIZE][SIZE],std::string start,std::string final,std::string ver[SIZE]) {
  int d[SIZE]; // минимальное расстояние
  int v[SIZE]; // посещенные вершины
  int temp, minindex, min;
  int begin_index = 0;
  int end_index = 0;
  for (int i = 0; i < SIZE; i++) {
    if (ver[i] == start) {
      begin_index = i;
    }
  }
  for (int i = 0; i < SIZE; i++) {
    if (ver[i] == final) {
      end_index = i;
    }
  }
  if (((begin_index == 0) && (ver[0] != start)) ||
      ((end_index == 0) && (ver[0] != final))) {
    return -1;
  } else {

    for (int i = 0; i < SIZE; i++) {
      d[i] = 10000;
      v[i] = 1;
    }
    d[begin_index] = 0;
    // Шаг алгоритма
    do {
      minindex = 10000;
      min = 10000;
      for (int i = 0; i < SIZE;
           i++) { // Если вершину ещё не обошли и вес меньше min
        if ((v[i] == 1) && (d[i] < min)) { // Переприсваиваем значения
          min = d[i];
          minindex = i;
        }
      }
      // Добавляем найденный минимальный вес к текущему весу вершины и сравниваем с текущим минимальным весом вершины
      if (minindex != 10000) {
        for (int i = 0; i < SIZE; i++) {
          if (a[minindex][i] > 0) {
            temp = min + a[minindex][i];
            if (temp < d[i]) {
              d[i] = temp;
            }
          }
        }
        v[minindex] = 0;
      }
    } while (minindex < 10000);
    if (d[end_index]==10000){
      return 0;
    }
    else {
      return d[end_index];
    }
  }
}