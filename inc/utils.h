#ifndef _UTILS_H_
#define _UTILS_H_

enum direction {ASCENDING, DESCENDING};

template <typename T>
bool isSorted(T* tab, int len);

template <typename T>
T* generateTab(int size, float percent = 0, direction = ASCENDING);

template <typename T>
float sortDuration(void (*func)(T*, int), T* tab, int size);

template <typename T>
void print(T* tab, int size);

#endif
