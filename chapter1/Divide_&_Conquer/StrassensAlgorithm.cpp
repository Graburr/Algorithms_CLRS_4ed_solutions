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
void MatrixAddRecursive(Matrix<T> &A, Matrix<T> &B, Matrix<T> &C, size_t rowA,
                        size_t colA, size_t rowB, size_t colB, size_t rowC, size_t colC,
                        size_t n) {
  // Base case
  if (n == 1) {
    C[rowC][colC] = A[rowA][colA] + B[rowB][colB];
    return;
  }
  n /= 2;

  // Divide and Conquer
  MatrixAddRecursive(A, B, C, rowA, colA, rowB, colB, rowC, colC, n);
  MatrixAddRecursive(A, B, C, rowA + n, colA, rowB + n, colB, rowC + n, colC, n);

  MatrixAddRecursive(A, B, C, rowA, colA + n, rowB, colB + n, rowC, colC + n, n);
  MatrixAddRecursive(A, B, C, rowA + n, colA + n, rowB + n, colB + n, rowC + n, colC + n,
                     n);
}

template <typename T>
void MatrixSubstractRecursive(Matrix<T> &A, Matrix<T> &B, Matrix<T> &C, size_t rowA,
                              size_t colA, size_t rowB, size_t colB, size_t rowC,
                              size_t colC, size_t n) {
  // Base case
  if (n == 1) {
    C[rowC][colC] = A[rowA][colA] - B[rowB][colB];
    return;
  }
  n /= 2;

  // Divide and Conquer
  MatrixSubstractRecursive(A, B, C, rowA, colA, rowB, colB, rowC, colC, n);
  MatrixSubstractRecursive(A, B, C, rowA + n, colA, rowB + n, colB, rowC + n, colC, n);

  MatrixSubstractRecursive(A, B, C, rowA, colA + n, rowB, colB + n, rowC, colC + n, n);
  MatrixSubstractRecursive(A, B, C, rowA + n, colA + n, rowB + n, colB + n, rowC + n,
                           colC + n, n);
}

#include <vector>

template <typename T> using Matrix = std::vector<std::vector<T>>;

template <typename T>
void SquareMatrixMultiplyStrassens(Matrix<T> &A, Matrix<T> &B, Matrix<T> &C, size_t rowA,
                                   size_t colA, size_t rowB, size_t colB, size_t rowC,
                                   size_t colC, size_t n) {
  if (n == 1) {
    C[rowC][colC] += A[rowA][colA] * B[rowB][colB];
    return;
  }

  n /= 2;

  Matrix<T> S1(n, std::vector<T>(n, 0)), S2(n, std::vector<T>(n, 0)),
      S3(n, std::vector<T>(n, 0)), S4(n, std::vector<T>(n, 0)),
      S5(n, std::vector<T>(n, 0)), S6(n, std::vector<T>(n, 0)),
      S7(n, std::vector<T>(n, 0)), S8(n, std::vector<T>(n, 0)),
      S9(n, std::vector<T>(n, 0)), S10(n, std::vector<T>(n, 0));

  MatrixSubstractRecursive(B, B, S1, rowB, colB + n, rowB + n, colB + n, 0, 0, n);
  MatrixAddRecursive(A, A, S2, rowA, colA, rowA, colA + n, 0, 0, n);
  MatrixAddRecursive(A, A, S3, rowA + n, colA, rowA + n, colA + n, 0, 0, n);
  MatrixSubstractRecursive(B, B, S4, rowB + n, colB, rowB, colB, 0, 0, n);
  MatrixAddRecursive(A, A, S5, rowA, colA, rowA + n, colA + n, 0, 0, n);
  MatrixAddRecursive(B, B, S6, rowB, colB, rowB + n, colB + n, 0, 0, n);
  MatrixSubstractRecursive(A, A, S7, rowA, colA + n, rowA + n, colA + n, 0, 0, n);
  MatrixAddRecursive(B, B, S8, rowB + n, colB, rowB + n, colB + n, 0, 0, n);
  MatrixSubstractRecursive(A, A, S9, rowA, colA, rowA + n, colA, 0, 0, n);
  MatrixAddRecursive(B, B, S10, rowB, colB, rowB, colB + n, 0, 0, n);

  Matrix<T> P1(n, std::vector<T>(n, 0)), P2(n, std::vector<T>(n, 0)),
      P3(n, std::vector<T>(n, 0)), P4(n, std::vector<T>(n, 0)),
      P5(n, std::vector<T>(n, 0)), P6(n, std::vector<T>(n, 0)),
      P7(n, std::vector<T>(n, 0));

  SquareMatrixMultiplyStrassens(A, S1, P1, rowA, colA, 0, 0, 0, 0, n);
  SquareMatrixMultiplyStrassens(S2, B, P2, 0, 0, rowB + n, colB + n, 0, 0, n);
  SquareMatrixMultiplyStrassens(S3, B, P3, 0, 0, rowB, colB, 0, 0, n);
  SquareMatrixMultiplyStrassens(A, S4, P4, rowA + n, colA + n, 0, 0, 0, 0, n);
  SquareMatrixMultiplyStrassens(S5, S6, P5, 0, 0, 0, 0, 0, 0, n);
  SquareMatrixMultiplyStrassens(S7, S8, P6, 0, 0, 0, 0, 0, 0, n);
  SquareMatrixMultiplyStrassens(S9, S10, P7, 0, 0, 0, 0, 0, 0, n);

  MatrixAddRecursive(P4, P5, C, 0, 0, 0, 0, rowC, colC, n);
  MatrixAddRecursive(C, P6, C, rowC, colC, 0, 0, rowC, colC, n);
  MatrixSubstractRecursive(C, P2, C, rowC, colC, 0, 0, rowC, colC, n);

  MatrixAddRecursive(P1, P2, C, 0, 0, 0, 0, rowC, colC + n, n);
  MatrixAddRecursive(P3, P4, C, 0, 0, 0, 0, rowC + n, colC, n);
  MatrixAddRecursive(P1, P5, C, 0, 0, 0, 0, rowC + n, colC + n, n);
  MatrixSubstractRecursive(C, P3, C, rowC + n, colC + n, 0, 0, rowC + n, colC + n, n);
  MatrixSubstractRecursive(C, P7, C, rowC + n, colC + n, 0, 0, rowC + n, colC + n, n);
}

int main() {
  Matrix<int> A = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};

  Matrix<int> B = {{16, 15, 14, 13}, {12, 11, 10, 9}, {8, 7, 6, 5}, {4, 3, 2, 1}};

  size_t n = 4;
  Matrix<int> C(n, std::vector<int>(n, 0));

  SquareMatrixMultiplyStrassens(A, B, C, 0, 0, 0, 0, 0, 0, n);

  std::cout << "Result of A x B:" << std::endl;
  PrintMatrix(C);

  return 0;
}