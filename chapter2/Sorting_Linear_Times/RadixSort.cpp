#include "RadixSort.h"

template <typename T> void RadixSort(std::vector<T> &A, size_t n, int d) {
  std::vector<T> values_sorted(n);
  for (int i = 0, exp = 1; i < d; ++i, exp *= 10) {
    if (i % 2 == 0) {
      CountingSort(A, values_sorted, n, exp, 10);
    } else {
      CountingSort(values_sorted, A, n, exp, 10);
    }
  }

  // values_sorted contains the result of sorting, for that the move is need.
  if (d % 2 == 1) {
    A = std::move(values_sorted);
  }
}

int main() {
  std::vector<int> values = {430, 310, 556, 231, 749, 784, 982, 167, 613};
  RadixSort(values, 9, 3);

  for (const int val : values) {
    std::cout << val << ", ";
  }
  std::cout << std::endl;
}