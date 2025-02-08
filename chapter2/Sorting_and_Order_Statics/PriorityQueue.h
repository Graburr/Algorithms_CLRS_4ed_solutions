#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
#include "HeapSort.h"

template <typename T> NodeHeapTree<T> MaxHeapMaximum(HeapTree<T> &heap_tree);

template <typename T> NodeHeapTree<T> MaxHeapExtractMax(HeapTree<T> &heap_tree);

template <typename T>
void MaxHeapIncrease(HeapTree<T> &heap_tree, NodeHeapTree<T> &x, int key);

template <typename T> void MaxHeapInsert(HeapTree<T> &heap_tree, NodeHeapTree<T> &&x);

#endif