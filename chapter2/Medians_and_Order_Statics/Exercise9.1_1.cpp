#include <iostream>
#include <vector>

std::pair<int, int> findSecondSmallestTournament(const std::vector<int> &A) {
  int n = A.size();
  if (n < 2)
    throw std::invalid_argument("Array must have at least two elements.");

  std::vector<int> tournament(A);

  while (tournament.size() > 2) {
    std::vector<int> next_round;
    for (size_t i = 0; i < tournament.size(); i += 2) {
      if (i + 1 < tournament.size()) {
        int a = tournament[i], b = tournament[i + 1];
        if (a < b) {
          next_round.push_back(a);
        } else {
          next_round.push_back(b);
        }
      } else {
        next_round.push_back(tournament[i]);
      }
    }
    tournament = next_round;
  }

  int min_value, second_min;

  if (tournament[0] < tournament[1]) {
    min_value = tournament[0];
    second_min = tournament[1];
  } else {
    min_value = tournament[1];
    second_min = tournament[0];
  }

  return {min_value, second_min};
}

int main() {
  std::vector<int> A = {5, 2, 8, 9, 10, 7, 4, 6};
  auto result = findSecondSmallestTournament(A);
  std::cout << "Smallest: " << result.first << ", Second Smallest: " << result.second
            << std::endl;
  return 0;
}