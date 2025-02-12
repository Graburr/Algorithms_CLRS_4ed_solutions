#include "RandomizedSelect.h"
#include "../QuickSort/RandomQuickSort.h"

template <typename T>
T RandomizedSelect(std::vector<T> &A, size_t p, size_t r, size_t i) {
  if (p == r) {
    return A[p];
  }
  size_t q = RandomPartition(A, p, r);
  size_t k = q - p + 1;

  if (i == k) {
    return A[q];
  } else if (i < k) {
    return RandomizedSelect(A, p, q - 1, i);
  } else {
    return RandomizedSelect(A, q + 1, r, i - k);
  }
}

int main() {
  srand(time(NULL));

  return 0;
}