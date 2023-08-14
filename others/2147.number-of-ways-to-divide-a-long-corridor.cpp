#include <string>
#include <vector>

class Solution {
  const static long long M = 1e9 + 7;

public:
  int numberOfWays(std::string corridor) {
    int n = corridor.size();

    std::vector<int> seats;
    for (int i = 0; i < n; i++) {
      if (corridor[i] == 'S')
        seats.push_back(i);
    }

    if (seats.size() == 0) return 0;
    if (seats.size() == 2) return 1;
    if (seats.size() % 2 != 0) return 0;

    long long ret = 1;
    for (int i = 2; i + 2 <= seats.size(); i += 2) {
      int a = seats[i] - seats[i - 1];
      ret *= (long long) a;
      ret %= M;
    }
    return ret;
  }
};
