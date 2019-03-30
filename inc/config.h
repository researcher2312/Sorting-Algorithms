typedef int TYPE;
int sizes[]={10000, 50000, 100000, 500000, 1000000};
fillData filling[] = {{0,ASCENDING}, {50, ASCENDING}, {75, ASCENDING}, {95, ASCENDING}, {99.7, ASCENDING}, {100, DESCENDING}};
void (*sortingFunctions[])(TYPE*, int) = {mergesort<TYPE>, quicksort<TYPE>, introsort<TYPE>};
std::string functionNames[]={"mergesort", "quicksort", "introsort"};
