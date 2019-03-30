#include <iostream>
#include "sort.h"
#include "utils.h"
#include "config.h"


using namespace std;

int main(){
  int counter=0;
  for(auto func: sortingFunctions){
    cerr << functionNames[counter++] << '\n';
    for(auto fill: filling){
      cerr << '\t' << fill.percent << "% " << fill.dir << '\n';
      for(auto size: sizes){
        cerr << "\t\t" << size << ' ';
        float time = 0;
        for(int i=0; i<100; i++){
          TYPE* tab = generateTab<TYPE>(size, fill.percent, fill.dir);
          time += sortDuration(func, tab, size);
          delete tab;
        }
        time /= 100;
        cerr << time << '\n';
      }
      cerr << '\n';
    }
    cerr << '\n';
  }
  return 0;
}
