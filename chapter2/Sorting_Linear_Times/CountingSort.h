#ifndef COUNTINGSORT_H
#define COUNTINGSORT_H
#include <iostream>
#include <memory>
#include <vector>

template <typename T> std::vector<T> CountingSort(std::vector<T> &A, size_t n, size_t k);
// Give the output vector initialized, used for radix sort.
// B --> the otuput vector.
// exp --> Indicate if we take units, dozens, hundreds, etc.
// base --> Base of the numbers: decimal, binary, octal, etc.
template <typename T>
void CountingSort(std::vector<T> &A, std::vector<T> &B, size_t n, int exp, int base = 10);

#endif