#include "PriorityQueue.h"

template <typename T> NodeHeapTree<T> MaxHeapMaximum(HeapTree<T> &heap_tree) {
  if (heap_tree.heap_size < 1) {
    throw std::underflow_error("Heap underflow\n");
  }
  return heap_tree.A[0];
}

template <typename T> NodeHeapTree<T> MaxHeapExtractMax(HeapTree<T> &heap_tree) {
  NodeHeapTree<T> max = MaxHeapMaximum(heap_tree);
  heap_tree.heap_size--;
  swap(heap_tree.A[0], heap_tree.A[heap_tree.heap_size]);
  MaxHeapify(heap_tree, 0);
  return max;
}

template <typename T>
void MaxHeapIncrease(HeapTree<T> &heap_tree, NodeHeapTree<T> &x, int k) {
  if (k < x.key) {
    throw std::runtime_error("new key is smaller than current key\n");
  }
  x.key = k;
  size_t i = x.index;

  while (i > 0 && heap_tree.A[Parent(i)].key < heap_tree.A[i].key) {
    swap(heap_tree.A[i], heap_tree.A[Parent(i)]);
    i = Parent(i);
  }
}

template <typename T> void MaxHeapInsert(HeapTree<T> &heap_tree, NodeHeapTree<T> &&x) {
  int key = x.key;
  x.key = INT32_MIN;

  if (heap_tree.heap_size == heap_tree.A.size()) {
    heap_tree.A.emplace_back(std::move(x));
  } else {
    heap_tree.A.insert(heap_tree.A.begin() + heap_tree.heap_size, std::move(x));
  }

  heap_tree.A[heap_tree.heap_size].index = heap_tree.heap_size;
  ++heap_tree.heap_size;
  MaxHeapIncrease(heap_tree, heap_tree.A[heap_tree.heap_size - 1], key);
}

template <typename T> void printHeap(const HeapTree<T> &heap) {
  std::cout << "Elements: ";
  for (size_t i = 0; i < heap.heap_size; ++i) {
    std::cout << "[i:" << heap.A[i].index << " k:" << heap.A[i].key
              << " v:" << *heap.A[i].value << "] ";
  }
  std::cout << "\n\n";
}

int main() {
  HeapTree<int> heap;
  printHeap(heap);

  MaxHeapInsert(heap, NodeHeapTree<int>(120, 5, 0));
  printHeap(heap);

  NodeHeapTree<int> node2(40, 3, 1);
  MaxHeapInsert(heap, std::move(node2));
  printHeap(heap);
  NodeHeapTree<int> node3(70, 7, 2);
  MaxHeapInsert(heap, std::move(node3));
  printHeap(heap);

  MaxHeapExtractMax(heap);
  printHeap(heap);

  NodeHeapTree<int> node4(90, 4, 3);
  MaxHeapInsert(heap, std::move(node4));
  printHeap(heap);

  return 0;
}