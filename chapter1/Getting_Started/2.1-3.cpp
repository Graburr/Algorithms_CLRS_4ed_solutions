#include <iostream>
#include <vector>

template <typename T> void InsertionSort(std::vector<T> &values, size_t length) {
  for (size_t i = 1; i < length; i++) {
    T key = values[i];
    int j = i - 1; // changed to int to hold -1 value (avoid exception of overflow)

    // The only change made was the > of values[j] > key for values[j] < key
    while (j >= 0 && values[j] < key) {
      values[j + 1] = values[j];
      j--;
    }

    values[j + 1] = key;
  }
}

int main() {
  std::vector<int> values_unsorted = {5, 2, 4, 6, 1, 3};
  InsertionSort(values_unsorted, values_unsorted.size());

  for (const int value : values_unsorted) {
    std::cout << value << ", ";
  }

  std::cout << std::endl;
  return 0;
}