#ifndef _UTILS_H_
#define _UTILS_H_

#include <ctime>
#include <random>
#include <limits>
#include <algorithm>
#include <iostream>

using namespace std;

template <typename T>
bool isSorted(T* tab, int len);

template <typename T>
T* generateTab(int size, float percent = 0, bool direction = 0);

template <typename T>
float sortDuration(void (*func)(T*, int), T* tab, int size);

template <typename T>
void print(T* tab, int size);

#endif
