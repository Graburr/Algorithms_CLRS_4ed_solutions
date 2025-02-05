#include <iostream>
#include <vector>

template <typename T> using Matrix = std::vector<std::vector<T>>;

template <typename T> void PrintMatrix(const Matrix<T> &M) {
  for (const auto &row : M) {
    for (const auto &elem : row) {
      std::cout << elem << " ";
    }
    std::cout << std::endl;
  }
}

template <typename T>
void MatrixMultiplyRecursive(Matrix<T> &A, Matrix<T> &B, Matrix<T> &C, size_t rowA,
                             size_t colA, size_t rowB, size_t colB, size_t rowC,
                             size_t colC, size_t n) {
  // Base case
  if (n == 1) {
    C[rowC][colC] = C[rowC][colC] + A[rowA][colA] * B[rowB][colB];
    return;
  }
  n /= 2;

  // Divide and Conquer
  MatrixMultiplyRecursive(A, B, C, rowA, colA, rowB, colB, rowC, colC, n);
  MatrixMultiplyRecursive(A, B, C, rowA, colA + n, rowB + n, colB, rowC, colC, n);

  MatrixMultiplyRecursive(A, B, C, rowA, colA, rowB, colB + n, rowC, colC + n, n);
  MatrixMultiplyRecursive(A, B, C, rowA, colA + n, rowB + n, colB + n, rowC, colC + n, n);

  MatrixMultiplyRecursive(A, B, C, rowA + n, colA, rowB, colB, rowC + n, colC, n);
  MatrixMultiplyRecursive(A, B, C, rowA + n, colA + n, rowB + n, colB, rowC + n, colC, n);

  MatrixMultiplyRecursive(A, B, C, rowA + n, colA, rowB, colB + n, rowC + n, colC + n, n);
  MatrixMultiplyRecursive(A, B, C, rowA + n, colA + n, rowB + n, colB + n, rowC + n,
                          colC + n, n);
}

int main() {
  Matrix<int> A = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};

  Matrix<int> B = {{16, 15, 14, 13}, {12, 11, 10, 9}, {8, 7, 6, 5}, {4, 3, 2, 1}};

  size_t n = 4;
  Matrix<int> C(n, std::vector<int>(n, 0));

  MatrixMultiplyRecursive(A, B, C, 0, 0, 0, 0, 0, 0, n);

  std::cout << "Result of A x B:" << std::endl;
  PrintMatrix(C);

  return 0;
}