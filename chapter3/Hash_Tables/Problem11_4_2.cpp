#include <iostream>
#include <vector>

enum class SlotState { EMPTY, DELETED, OCCUPIED };

inline size_t HashFunction(size_t n, int k, int i) { return k + i * (1 + (k % n - 1)); }

void HashDelete(std::vector<std::pair<int, SlotState>> &hash_table, int k) {
  size_t i = 0;
  size_t n = hash_table.size();

  do {
    auto &q = hash_table[HashFunction(n, k, i)];
    if (q.second == SlotState::EMPTY) {
      std::cout << "The value to delete doesn't exist\n";
    } else if (q.second == SlotState::DELETED) {
      std::cout << "The value was deleted before\n";
    } else if (q.first == k) {
      q.second = SlotState::DELETED;
    }
    ++i;
  } while (i != n);
}

auto HashInsert(std::vector<std::pair<int, SlotState>> &hash_table, int k) {
  size_t i = 0;
  size_t n = hash_table.size();

  do {
    auto &q = hash_table[HashFunction(n, k, i)];
    if (q.second == SlotState::EMPTY || q.second == SlotState::DELETED) {
      q.first = k;
      return q;
    }
    ++i;
  } while (i != n);
  throw std::domain_error(
      "The key couldn't be inserted because all slots are occupied\n");
}

auto HashSearch(std::vector<std::pair<int, SlotState>> &hash_table, int k) {
  size_t i = 0;
  size_t n = hash_table.size();

  do {
    auto &q = hash_table[HashFunction(n, k, i)];
    if (q.second == SlotState::OCCUPIED && q.first == k) {
      return q;
    } else if (q.second == SlotState::DELETED && q.first == k) {
      std::cout << "The value being searched was deleted before\n";
      break;
    } else if (q.second == SlotState::EMPTY) {
      std::cout << "The value doesn't exist\n";
    }
    ++i;
  } while (i != n);
  // Indicate no value was found
  return std::pair<int, SlotState>(0, SlotState::EMPTY);
}