#ifndef RANDOMQUICKSORT_H
#define RANDOMQUICKSORT_H
#include "QuickSort.h"

template <typename T> void RandomQuickSort(std::vector<T> &A, size_t p, size_t r);
template <typename T> size_t RandomPartition(std::vector<T> &A, size_t p, size_t r);

#endif