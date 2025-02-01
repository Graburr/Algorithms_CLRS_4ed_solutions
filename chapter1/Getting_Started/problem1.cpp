#include <cmath>
#include <iostream>
#include <limits>
#include <string_view>
#include <vector>

double log2OfN(double t) { return std::pow(2, t); }

double squareRootOfN(double t) { return t * t; }

double linearN(double t) { return t; }

double nMultipliedByLog2OfN(double t) {
  double left = 0;
  double right = t;

  for (int i = 0; i < 100; i++) {
    double mid = (left + right) / 2;
    if (mid * std::log2(mid) > t) {
      right = mid;
    } else {
      left = mid;
    }
  }

  return left;
}

double pow2OfN(double t) { return std::sqrt(t); }

double pow3OfN(double t) { return std::cbrt(t); }

double powNOf2(double t) { return std::log2(t); }

double factorialOfN(double t) {
  double fact = 1;
  double n = 1;
  while (fact <= t) {
    n++;
    fact *= n;
  }
  return n - 1;
}

int main() {
  const std::vector<std::string_view> time_units = {"Second", "Minute", "Hour",   "Day",
                                                    "Month",  "Year",   "Century"};
  const std::vector<double> time_values = {1e6,       6e7,        3.6e9,     8.64e10,
                                           2.6298e12, 3.15576e13, 3.15576e15};

  std::cout << "\nCalculating maximum n for each complexity function:\n\n";

  for (size_t i = 0; i < time_units.size(); ++i) {
    std::cout << time_units[i] << " -->\n";
    std::cout << "log2(n) --> n: " << log2OfN(time_values[i]) << "\n";
    std::cout << "sqrt(n) --> n: " << squareRootOfN(time_values[i]) << "\n";
    std::cout << "linear(n) --> n: " << linearN(time_values[i]) << "\n";
    std::cout << "n * log2(n) --> n: " << nMultipliedByLog2OfN(time_values[i]) << "\n";
    std::cout << "n^2 --> n: " << pow2OfN(time_values[i]) << "\n";
    std::cout << "n^3 --> n: " << pow3OfN(time_values[i]) << "\n";
    std::cout << "2^n --> n: " << powNOf2(time_values[i]) << "\n";
    std::cout << "n! --> n: " << factorialOfN(time_values[i]) << "\n\n";
  }

  return 0;
}
