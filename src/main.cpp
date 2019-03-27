#include <iostream>
#include "sort.h"
#include "utils.h"
#include <ctime>


using namespace std;

int main(){
  int size = 10000000;
  int* tab = generateTab<int>(size);

  // int tab[10]={2,5,7,4,7,9,12,3,4,5};


  cout << sortDuration(mergesort, tab, 0, size-1);

  return 0;
}
