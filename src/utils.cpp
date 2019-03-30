#include <ctime>
#include <random>
#include <limits>
#include <algorithm>
#include <iostream>
#include "utils.h"

using namespace std;

template <typename T>
float sortDuration(void (*func)(T*, int), T* tab, int size){
  clock_t start = clock();
  func(tab, size);
  clock_t stop = clock();
  if(isSorted(tab, size))
    return (stop-start)*1000/CLOCKS_PER_SEC;
  else
    return -1;
}

template float sortDuration(void (*)(int*, int), int*, int);

template <typename T>
T* generateTab(int size, float percent, direction dir){
  default_random_engine generator(time(nullptr));
  uniform_int_distribution<T> distribution(numeric_limits<T>::min(), numeric_limits<T>::max());

  T* tab = new T [size];
  for(int i=0; i<size; i++){
    tab[i] = distribution(generator);
  }

  if(percent!=0){
    int fill = (int)size*percent/100;
    if(dir==ASCENDING)sort(tab, tab+fill, [](T a, T b){return a<b;});
    if(dir==DESCENDING)sort(tab, tab+fill, [](T a, T b){return a>b;});
  }

  return tab;

}

template int* generateTab(int, float, direction);

template <typename T>
bool isSorted(T* tab, int len){
  if(len==1)return 1;
  for(int i=0; i<len-1; i++){
    if(tab[i]>tab[i+1]){
      return 0;
    }
  }
  return 1;
}

template bool isSorted(int* tab, int len);

template <typename T>
void print(T* tab, int size){
  for(int i=0; i<size; i++)
    cout << tab[i] << ' ';
}

template void print(int* tab, int size);
