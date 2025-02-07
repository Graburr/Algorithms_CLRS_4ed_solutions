#include <iostream>
#include <vector>

template <typename T> struct HeapTree {
  std::vector<T> &A;
  size_t heap_size;
};

inline size_t Parent(size_t i) { return i / 2; }

inline size_t Left(size_t i) { return 2 * i; }

inline size_t Right(size_t i) { return 2 * i + 1; }

template <typename T> void MaxHeapify(HeapTree<T> &heap_tree, size_t i) {
  size_t left = Left(i);
  size_t right = Right(i);
  size_t largest = i;

  if (left < heap_tree.heap_size && heap_tree.A[left] > heap_tree.A[i]) {
    largest = left;
  }
  if (right < heap_tree.heap_size && heap_tree.A[right] > heap_tree.A[largest]) {
    largest = right;
  }
  if (largest != i) {
    std::swap(heap_tree.A[i], heap_tree.A[largest]);
    MaxHeapify(heap_tree, largest);
  }
}

template <typename T> void BuildMaxHeap(HeapTree<T> &heap_tree, size_t n) {
  for (size_t i = n / 2; i-- > 0;) {
    MaxHeapify(heap_tree, i);
  }
}

template <typename T> void HeapSort(HeapTree<T> &heap_tree, size_t n) {
  BuildMaxHeap(heap_tree, n);
  for (size_t i = n - 1; i > 0; --i) {
    std::swap(heap_tree.A[0], heap_tree.A[i]);
    --heap_tree.heap_size;
    MaxHeapify(heap_tree, 0);
  }
}

int main() {
  std::vector<int> A = {1, 4, 7, 19, 18, 2, 9, 6};
  HeapTree<int> heap_tree = {A, A.size()};
  HeapSort(heap_tree, heap_tree.heap_size);

  for (const int element : A) {
    std::cout << element << ", ";
  }
  std::cout << std::endl;
  return 0;
}