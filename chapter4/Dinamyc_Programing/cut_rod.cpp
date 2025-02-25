#include <iostream>
#include <vector>

// This is using Top-down thecnique.
int CutRodAux(std::vector<int> &prices, size_t n, std::vector<int> &revenues) {
  if (revenues[n] >= INT32_MIN) {
    return revenues[n];
  }

  int revenue = INT32_MIN;

  if (n == 0) {
    revenue = 0;
  } else {
    for (size_t i = 1; i < n; ++i) {
      revenue = std::max(revenue, prices[i] + CutRodAux(prices, n - i, revenues));
    }
  }

  revenues[n] = revenue;
  return revenue;
}

int CutRod(std::vector<int> &prices, size_t n) {
  std::vector<int> revenues(n, INT32_MIN);
  return CutRodAux(prices, n, revenues);
}

// This is the preferred way of implementing that.
int BottomUpCutRod(std::vector<int> &prices, size_t n) {
  std::vector<int> calc_sol(n + 1);

  for (size_t i = 1; i <= n; ++i) {
    int q = INT32_MIN;

    for (size_t j = 1; j <= i; ++j) { // position of first cut
      q = std::max(q, prices[j - 1] + calc_sol[i - j]);
    }

    calc_sol[i] = q;
  }

  return calc_sol[n];
}

void PrintCutRodSol(std::vector<int> &calc_sol, std::vector<size_t> &slices, size_t n) {
  std::cout << "Price --> " << calc_sol[n] << "\t Slices: ";
  while (n > 1) {
    if (slices[n - 1] == 0) {
      std::cout << "no slices is needed\n";
      return;
    }

    std::cout << slices[n - 1] << ", ";
    n -= slices[n - 1];
  }
}

// Print the maximum result and also the slice you have to do
void ExBottomUpCutRod(std::vector<int> &prices, size_t n) {
  std::vector<int> calc_sol(n + 1);
  std::vector<size_t> slices(n);

  for (size_t i = 1; i <= n; ++i) {
    int q = INT32_MIN;

    for (size_t j = 1; j <= i; ++j) { // position of first cut
      if (q < prices[j - 1] + calc_sol[i - j]) {
        q = prices[j - 1] + calc_sol[i - j];
        slices[i - 1] = j;
      }
    }

    calc_sol[i] = q;
  }

  PrintCutRodSol(calc_sol, slices, n);
}

// Apply the fixed amount of cutting cost to each cut that is done.
void ExBottomUpCutRodCostCutting(std::vector<int> &prices, size_t n, const int COST_CUT) {
  std::vector<int> calc_sol(n + 1);
  std::vector<size_t> slices(n);

  for (size_t i = 1; i <= n; ++i) {
    int q = prices[i - 1];

    for (size_t j = 1; j <= i; ++j) { // position of first cut
      int q_new = prices[j - 1] + calc_sol[i - j] - COST_CUT;

      if (q < q_new) {
        q = q_new;
        slices[i - 1] = j;
      }
    }

    calc_sol[i] = q;
  }

  PrintCutRodSol(calc_sol, slices, n);
}

int main() {
  std::vector<int> prices = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
  size_t n = 4;

  std::cout << "For size " << n << " the optimal solution is:\n";
  ExBottomUpCutRodCostCutting(prices, n, 3);
  std::cout << std::endl;

  return 0;
}