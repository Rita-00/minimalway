#include <iostream>
#include <fstream>
#include "lib.h"

using namespace std;
ifstream file ("../f.txt");

int main(){
  int a[SIZE][SIZE]={0}; // матрица связей
  string ver[SIZE]={" "};//вершины

  read_file(file,a,ver);


  string start,final;
  cout<<"введите исходный пункт";
  cin>>start;

  cout<<"введите конечный пункт";
  cin>>final;

  // Вывод матрицы связей
  for (int i = 0; i<SIZE; i++)
  {
    for (int j = 0; j<SIZE; j++)
      printf("%5d ", a[i][j]);
    printf("\n");
  }
  if (minway(a,start,final,ver)==-1){
    cout<<"данного пункта нет в графе";
  }
  else {
    cout << minway(a, start, final, ver);
  }
  return 0;
}