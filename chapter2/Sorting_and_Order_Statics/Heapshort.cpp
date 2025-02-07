#include <iostream>
#include <vector>

inline size_t Parent(size_t i) { return i / 2; }

inline size_t Left(size_t i) { return 2 * i; }

inline size_t Right(size_t i) { return 2 * i + 1; }

template <typename T> void MaxHeapify(std::vector<T> &A, size_t i) {
  size_t left = Left(i);
  size_t right = Right(i);
  size_t largest = i;

  if (left < A.size() && A[left] > A[i]) {
    largest = left;
  }
  if (right < A.size() && A[right] > A[largest]) {
    largest = right;
  }
  if (largest != i) {
    std::swap(A[i], A[largest]);
    MaxHeapify(A, largest);
  }
}