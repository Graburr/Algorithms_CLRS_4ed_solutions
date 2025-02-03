#include <iostream>
#include <vector>

template <typename T> void Merge(std::vector<T> &elements, size_t p, size_t q, size_t r) {
  size_t length_left = q - p + 1; // A[p:q]
  size_t length_right = r - q;    // A[q + 1, r]
  std::vector<T> left(length_left);
  std::vector<T> right(length_right);

  for (size_t i = 0; i < length_left; i++) {
    left[i] = elements[p + i];
  }

  for (size_t i = 0; i < length_right; i++) {
    right[i] = elements[i + q + 1];
  }

  size_t i = 0;
  size_t j = 0;
  size_t k = p;

  while (i < length_left && j < length_right) {
    if (left[i] <= right[j]) {
      elements[k] = left[i];
      i++;
    } else {
      elements[k] = right[j];
      j++;
    }
    k++;
  }

  while (i < length_left) {
    elements[k] = left[i];
    i++;
    k++;
  }

  while (j < length_right) {
    elements[k] = right[j];
    j++;
    k++;
  }
}

template <typename T> void MergeSort(std::vector<T> &elements, size_t p, size_t r) {
  if (p >= r) {
    return;
  }

  size_t q = (p + r) / 2;
  // Divide and conquer
  MergeSort(elements, p, q);     // Recursively sort A[p:q]
  MergeSort(elements, q + 1, r); // Recursively sort A[p:q + 1]
  Merge(elements, p, q, r);
}

int main() {
  std::vector<int> values = {1, 5, 4, 2, 7, 3, 6, 9};
  MergeSort(values, 0, values.size() - 1);

  for (const int value : values) {
    std::cout << value << ", ";
  }
  std::cout << std::endl;
  return 0;
}