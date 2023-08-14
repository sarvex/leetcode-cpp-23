#include <algorithm>
#include <vector>

class Solution {
public:
  int shipWithinDays(std::vector<int> &weights, int D) {
    int left = std::numeric_limits<int>::max();
    int right = 0;
    for (auto x: weights) {
      left = std::min(left, x);
      right += x;
    }

    while (left < right) {
      int cap = left + (right - left) / 2;
      if (checkOK(weights, cap, D))
        right = cap;
      else
        left = cap + 1;
    }

    return left;
  }

  bool checkOK(std::vector<int> &weights, int cap, int D) {
    int count = 0;
    for (size_t i = 0; i < weights.size();) {
      size_t j = i;
      int sum = 0;
      while (j < weights.size() && sum + weights[j] <= cap) {
        sum += weights[j];
        j++;
      }
      count += 1;
      if (count > D)
        return false;
      i = j;
    }
    return true;
  }
};
