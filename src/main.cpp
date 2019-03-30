#include <iostream>
#include "sort.h"
#include "utils.h"
#include "config.h"


using namespace std;

int main(){
  for(auto func: sorting){
    for(auto fill: filling){
      for(auto size: sizes){
        float time = 0;
        for(int i=0; i<100; i++){
          TYPE* tab = generateTab<TYPE>(size, fill.percent, fill.dir);
          time += sortDuration(func, tab, size);
          delete tab;
        }
        time /= 100;
        cerr << time << ' ';
      }
    }
  }
  return 0;
}
