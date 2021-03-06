#include <random>
#include <limits>
#include <algorithm>
#include <iostream>
#include <sys/time.h>
#include "utils.h"

using namespace std;

/*Counts time in ms and returns it if the array is sorted, otherwise returns -1*/
template <typename T>
float sortDuration(void (*func)(T*, int), T* tab, int size){
  timeval t1, t2;
  double elapsedTime;
  gettimeofday(&t1, NULL);
  func(tab, size);
  gettimeofday(&t2, NULL);
  if(isSorted(tab, size)){
    elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
    elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;   //us to ms
    return elapsedTime;
  }
  else
    return -1;
}

template float sortDuration(void (*)(int*, int), int*, int);

/*Generates random array of given size and sorts it in given direction and part*/
template <typename T>
T* generateTab(int size, float percent, direction dir){
  random_device r;
  default_random_engine generator(r());
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

/*Checks arrays for being sorted, returns 1 if they are and 0 if not*/
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

/*prints arrays*/
template <typename T>
void print(T* tab, int size){
  for(int i=0; i<size; i++)
    cout << tab[i] << ' ';
}

template void print(int* tab, int size);
