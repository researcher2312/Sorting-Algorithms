#include "sort.h"
#include "utils.h"
#include "config.h"
#include <ctime>
#include <iostream>


using namespace std;

int main(){

for(auto func: sorting){
  for(auto fill: filling){
    for(auto size: sizes){
      TYPE* tab = generateTab<TYPE>(size, fill.percent, fill.dir);
      cout << sortDuration(func, tab, size) << ' ';
      delete tab;
    }
  }
}
  return 0;
}
