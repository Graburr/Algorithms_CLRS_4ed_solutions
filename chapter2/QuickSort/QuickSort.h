#ifndef QUICKSORT_H
#define QUICKSORT_H
#include <iostream>
#include <vector>

template <typename T> void QuickSort(std::vector<T> A, size_t p, size_t r);
template <typename T> size_t Partition(std::vector<T> A, size_t p, size_t r);

#endif