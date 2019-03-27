#include "sort.h"
#include <iostream>

//******************************Mergesort

template <typename T>
void merge(T *set, int start, int middle, int end){
  T *copy = new T [end-start+1];

  int a=start, b=middle+1, q=0;
  while(a<=middle && b<=end){
    if(set[a]<set[b])
      copy[q++]=set[a++];
    else
      copy[q++]=set[b++];
  }

  while(a<=middle)
    copy[q++]=set[a++];
  while(b<=end)
    copy[q++]=set[b++];

  for(int i=0; i<end-start+1; i++)
    set[start+i]=copy[i];
  delete copy;
}

template <typename T>
void mergesort(T *set, int start, int end){
  if(start==end)
    return;
  int middle=(start+end)/2;
  mergesort(set, start, middle);
  mergesort(set, middle+1, end);
  merge<int>(set, start, middle, end);
}

template void mergesort<int>(int*,int,int);

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

// template <typename T>
// void Heapify (T *tab, int wezel, int r)
// {
//
// }
//
// template <typename T>
// void heapsort(T* tab, int l, int r){
//
// }
