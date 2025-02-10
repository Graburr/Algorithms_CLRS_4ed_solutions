#include "RandomQuickSort.h"
#include <stdlib.h>

template <typename T> void RandomQuickSort(std::vector<T> &A, size_t p, size_t r) {
  if (p < r) {
    size_t q = RandomPartition(A, p, r);
    RandomQuickSort(A, p, q - 1);
    RandomQuickSort(A, q + 1, r);
  }
}

template <typename T> size_t RandomPartition(std::vector<T> &A, size_t p, size_t r) {
  size_t i = rand() % p + r;
  std::swap(A[r], A[i]);
  return Partition(A, p, r);
}

int main() {
  srand(time(NULL));

  return 0;
}