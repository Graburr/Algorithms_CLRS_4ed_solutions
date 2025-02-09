#include "HeapSort.h"

template <typename T> void MaxHeapify(HeapTree<T> &heap_tree, size_t i) {
  size_t left = Left(i);
  size_t right = Right(i);
  size_t largest = i;

  if (left < heap_tree.heap_size && heap_tree.A[left].key > heap_tree.A[i].key) {
    largest = left;
  }
  if (right < heap_tree.heap_size && heap_tree.A[right].key > heap_tree.A[largest].key) {
    largest = right;
  }
  if (largest != i) {
    swap(heap_tree.A[i], heap_tree.A[largest]);
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
    swap(heap_tree.A[0], heap_tree.A[i]);
    --heap_tree.heap_size;
    MaxHeapify(heap_tree, 0);
  }
}

// Declared explicitly to use this especialization of the template on the file
// PriorityQueue.cpp
template void MaxHeapify<int>(HeapTree<int> &heap_tree, size_t i);
