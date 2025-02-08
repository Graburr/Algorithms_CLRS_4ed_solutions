#ifndef HEAPSORT_H
#define HEAPSORT_H
#include <iostream>
#include <memory>
#include <vector>

template <typename T> struct NodeHeapTree {
  std::unique_ptr<T> value;
  int key;
  size_t index; // Store in which index of the array is located

  NodeHeapTree() : value(nullptr), key(0), index(0) {}
  NodeHeapTree(std::unique_ptr<T> &&val, int k, size_t idx = 0)
      : value(std::move(val)), key(k), index(idx) {}
  NodeHeapTree(T &&val, int k, size_t idx = 0)
      : value(std::make_unique<T>(std::move(val))), key(k), index(idx) {}
  NodeHeapTree(NodeHeapTree &&node)
      : value(std::move(node.value)), key(node.key), index(node.index) {}

  NodeHeapTree &operator=(NodeHeapTree &&other) noexcept {
    if (this != &other) {
      value = std::move(other.value);
      key = other.key;
      index = other.index;
    }
    return *this;
  }

  NodeHeapTree(const NodeHeapTree &other) : key(other.key), index(other.index) {
    if (other.value) {
      value = std::make_unique<T>(*other.value);
    }
  }
};

template <typename T> struct HeapTree {
  std::vector<NodeHeapTree<T>> A;
  size_t heap_size;

  HeapTree() : heap_size(0) {}

  HeapTree(std::vector<NodeHeapTree<T>> &&nodes, size_t size)
      : A(std::move(nodes)), heap_size(size) {}
};

inline size_t Parent(size_t i) { return i / 2; }

inline size_t Left(size_t i) { return 2 * i; }

inline size_t Right(size_t i) { return 2 * i + 1; }

template <typename T> inline void swap(NodeHeapTree<T> &a, NodeHeapTree<T> &b) {
  std::swap(a.key, b.key);
  std::swap(a.index, b.index);
  a.value.swap(b.value);
}

template <typename T> void MaxHeapify(HeapTree<T> &heap_tree, size_t i);
template <typename T> void BuildMaxHeap(HeapTree<T> &heap_tree, size_t n);
template <typename T> void HeapSort(HeapTree<T> &heap_tree, size_t n);

#endif