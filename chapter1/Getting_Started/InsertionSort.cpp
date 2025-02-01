#include <iostream>
#include <vector>

/*
Loop invariant properties:

- Initialization: Show what invariant holds before first loop iteration. When i = 1, the
  subarray consist on only 1 element A[0] (original element in unordered vector). Also
  it's sorted because there is only 1 element in the subarray sorted.

- Maintenance: Show that after each iteration, the invariant is maintened. The body of the
  for loop works moving A[i - 1], A[i - 2], etc. to the right until it finds a proper
  position for A[i]. Then the subarray A[1:i] have the elements sorted. The invariant is
  preserved incrementing 'i' by 1.

- Termination: When the i value exceded the length, the loops terminates. Therefore the
  loop terminates once i = n + 1. Substituing i by n + 1, yields that the ordered subarray
  is A[1:n] that has the originally elements in A[1:n] but sorted. Hence the algorithm is
  correct.
*/

template <typename T> void InsertionSort(std::vector<T> &values, size_t length) {
  for (size_t i = 1; i < length; i++) {
    T key = values[i];
    size_t j = i - 1;

    while (j >= 0 && values[j] > key) {
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