#include "sort.h"
#include <iostream>
#include <cmath>

//******************************Mergesort

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

// template <typename T>
// T middle(T a, T b, T c){
//   if(a>=b)
//     if(b>=c)return b;
//     else
//       if(a>=c)return c;
//       else return a;
//   else
//     if(c>=b)return b;
//     else
//       if(a>=c)return a;
//       else return c;
// }

template <typename T>
int choosePivot(T* tab, int size){
  // if(r-l>20){
  //   return middle(tab[l], tab[(l+r)/2], tab[r]);
  // }
  // else
  return (size)/2;
}

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

template <typename T>
void introsort(T* tab, int size){
  introsort(tab, size, (int)floor(2*log2(size)));
  insertsort(tab, size);
}

template void introsort<int>(int*, int);
