#include "sort.h"
#include <iostream>

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
int choosePivot(T* tab, int l, int r){
  // if(r-l>20){
  //   return middle(tab[l], tab[(l+r)/2], tab[r]);
  // }
  // else
    return (l+r)/2;
}

template <typename T>
void quicksort(T* tab, int l, int r){
  int pivotIndex = choosePivot(tab, l, r);
  T pivot = tab[pivotIndex];
  swap(tab, pivotIndex, r);
  int changeIndex = l;
  for(int i=l; i<r; i++)
    if(tab[i] < pivot)
      swap(tab, i, changeIndex++);
  swap(tab, r, changeIndex);
  if(l < changeIndex-1)quicksort(tab, l, changeIndex-1);
  if(changeIndex+1 < r)quicksort(tab, changeIndex+1, r);
}

template void quicksort<int>(int*,int,int);

//*******************InsertSort

template <typename T>
void insertsort(T* tab, int l, int r){
  for(int i = l+1; i<=r; i++){
     T element = tab[i];
     int j=i-1;
     while(j>=l && tab[j]>element){
       tab[j+1]=tab[j];
       j--;
     }
    tab[j+1]=element;
  }
}

template void insertsort<int>(int*, int, int);

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
