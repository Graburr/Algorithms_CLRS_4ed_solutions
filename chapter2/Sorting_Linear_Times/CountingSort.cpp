#include "CountingSort.h"

// n --> Number of elements of A,
// k --> Max non negative value of array A.
template <typename T> std::vector<T> CountingSort(std::vector<T> &A, size_t n, size_t k) {
  std::vector<T> B(n);
  std::vector<T> C(k + 1, 0);

  // Number elements equals to i for each integer i = 0, 1, ..., k
  for (size_t j = 0; j < n; ++j) {
    ++C[A[j]];
  }

  // How many elements are less than or equal to i.
  for (size_t i = 1; i < k; ++i) {
    C[i] += C[i - 1];
  }

  for (size_t j = n; j > 0; --j) {
    B[C[A[j - 1]] - 1] = A[j - 1];
    --C[A[j - 1]]; // Handle duplciate values
  }
  return B;
}