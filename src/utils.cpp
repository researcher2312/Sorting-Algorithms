#include "utils.h"
#include <ctime>
#include <random>
#include <limits>


using namespace std;

template <typename T>
float sortDuration(void (*func)(T*, int, int), T* tab, int begin, int end){
  clock_t start = clock();
  func(tab, begin, end);
  clock_t stop = clock();
  if(isSorted(tab, end+1))
    return (stop-start)*1000/CLOCKS_PER_SEC;
  else
    return -1;
}

template float sortDuration(void (*)(int*, int, int), int*, int, int);

template <typename T>
T* generateTab(int size, bool direction, float percent){
  default_random_engine generator;
  uniform_int_distribution<T> distribution(numeric_limits<T>::min(), numeric_limits<T>::max());
  srand(time(nullptr));

  T* tab = new T [size];
  for(int i=0; i<size; i++){
    tab[i] = distribution(generator);
  }
  return tab;

}

template int* generateTab(int, bool, float);

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
