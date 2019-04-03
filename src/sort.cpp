#include <cmath>
#include "sort.h"

//******************************Mergesort

/*Merges two arrays*/
template <typename T>
void merge(T *tab, int middle, int end, T* copyTab){

  int a=0, b=middle+1, q=0;
  while(a<=middle && b<=end){
    if(tab[a]<tab[b])
      copyTab[q++]=tab[a++];
    else
      copyTab[q++]=tab[b++];
  }

  while(a<=middle)
    copyTab[q++]=tab[a++];
  while(b<=end)
    copyTab[q++]=tab[b++];

  for(int i=0; i<=end; i++)
    tab[i]=copyTab[i];
}

/*function used for normal work, when called with nullptr it creates the copy tab for copying durning the sorting
and sets the flag to 1. At the end, function with flag deletes the copy tab*/
template <typename T>
void mergesort(T *tab, int size, T* copyTab){
  if(size<2)
    return;
  bool flag = 0;
  if(copyTab == nullptr){
    copyTab = new T [size];
    flag = 1;
  }
  int middle = size/2;
  mergesort(tab, middle, copyTab);
  mergesort(tab+middle, size-middle, copyTab);
  merge(tab, middle-1, size-1, copyTab);
  if(flag) delete copyTab;
}

/*overloaded function used for calls, when it passes the nullptr it shows that it is the first call*/
template <typename T>
void mergesort(T* tab, int size){
  int* ptr {nullptr};
  mergesort(tab, size, ptr);
}

template void mergesort<int>(int*,int);
template void mergesort<int>(int*,int,int*);

//*********************Quicksort

template <typename T>
void swap(T* tab, int a, int b){
  T temp = tab[a];
  tab[a] = tab[b];
  tab[b] = temp;
}

template <typename T>
int choosePivot(T* tab, int size){
  return (size)/2;
}

/*function used for calls, after choosing the pivot it moves numbers to left or right and calls next quicksort*/
template <typename T>
void quicksort(T* tab, int size){
  int pivotIndex = choosePivot(tab, size);
  T pivot = tab[pivotIndex];
  swap(tab, pivotIndex, size-1);
  int changeIndex = 0;
  for(int i=0; i<size-1; i++)//size-1
    if(tab[i] < pivot)
      swap(tab, i, changeIndex++);
  swap(tab, size-1, changeIndex);
  if(0 < changeIndex-1)quicksort(tab, changeIndex);
  if(changeIndex+1 < size-1)quicksort(tab+changeIndex+1, size-changeIndex-1);//???
}

template void quicksort<int>(int*,int);

//*******************InsertSort

/*Insert sort used in Introspective sort*/
template <typename T>
void insertsort(T* tab, int size){
  for(int i=0; i<size; i++){
     T element = tab[i];
     int j=i-1;
     while(j>=0 && tab[j]>element){
       tab[j+1]=tab[j];
       j--;
     }
    tab[j+1]=element;
  }
}

template void insertsort<int>(int*, int);

//********************HeapSort

/*function used to return order to heap after taking the first element*/
template <typename T>
void heapDown (T *tab, int node, int size){
  T nodeValue = tab[node-1];
  while(node <= size/2){
    int nextNode = 2*node;
    if(nextNode < size && tab[nextNode-1] < tab[nextNode])
      nextNode++;
    if(nodeValue >= tab[nextNode-1])
      break;
    tab[node-1]=tab[nextNode-1];
    node=nextNode;
  }
tab[node-1]=nodeValue;
}

/*Heap sort used in Introspective sort*/
template <typename T>
void heapsort(T* tab, int N){
  for(int i=N/2; i>0; i--)
    heapDown(tab, i, N);
  while(N > 1){
    swap(tab, 0, N-1);
    N--;
    heapDown(tab, 1, N);
  }
}

template void heapsort<int>(int*, int);

//***********************introspective Sort

/*Similar to quick sort, but when max depth is reached it calls heap sort and when
the subsets are less than 9 elements it leaves them for insert sorting later*/
template <typename T>
void introsort(T* tab, int size, int availibleDepth){
  if(availibleDepth>0){
    heapsort(tab, size);
    return;
  }
  int pivotIndex = choosePivot(tab, size);
  T pivot = tab[pivotIndex];
  swap(tab, pivotIndex, size-1);
  int changeIndex = 0;
  for(int i=0; i<size-1; i++)
    if(tab[i] < pivot)
      swap(tab, i, changeIndex++);
  swap(tab, size-1, changeIndex);
  if(0<changeIndex-1 && changeIndex>9)introsort(tab, changeIndex, availibleDepth--);
  if(changeIndex+1<size-1 && size-changeIndex-1>9)introsort(tab+changeIndex+1, size-changeIndex-1, availibleDepth--);
}

/*Introspective sort used for calls, it counts the maximum call tree depth and passes it as argument.
After sorting the parts that were below 9 in length, final insert sort is called*/
template <typename T>
void introsort(T* tab, int size){
  introsort(tab, size, (int)floor(2*log2(size)));
  insertsort(tab, size);
}

template void introsort<int>(int*, int);
