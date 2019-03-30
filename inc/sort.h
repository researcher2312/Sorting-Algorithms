#ifndef SORT_HH
#define SORT_HH

template <typename T>
void mergesort (T* tab, int size, T* copyTab);

template <typename T>
void mergesort (T* tab, int size);

template <typename T>
void quicksort(T* tab, int size);

template <typename T>
void introsort(T* tab, int size);

template <typename T>
void heapsort(T* tab, int size);

template <typename T>
void insertsort(T*tab, int size);

#endif
