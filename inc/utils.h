#ifndef _UTILS_H_
#define _UTILS_H_

template <typename T>
bool isSorted(T* tab, int len);

template <typename T>
T* generateTab(int size, bool direction = 1, float percent = 100);

template <typename T>
float sortDuration(void (*func)(T*, int, int), T* tab, int begin, int end);
#endif
