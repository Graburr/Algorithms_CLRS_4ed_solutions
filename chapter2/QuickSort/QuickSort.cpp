#include "QuickSort.h"

template <typename T> void QuickSort(std::vector<T> &A, size_t p, size_t r) {
  if (p < r) {
    size_t q = Partition(A, p, r);
    QuickSort(A, p, q - 1);
    QuickSort(A, q + 1, r);
  }
}

template <typename T> size_t Partition(std::vector<T> &A, size_t p, size_t r) {
  T = A[r];
  size_t i = p;

  for (size_t j = p; j < r : ++j) {
    if (A[j] <= x) {
      std::swap(A[i], A[j]);
      ++i;
    }
  }
  std::swap(A[i], A[r]);
  return i;
}