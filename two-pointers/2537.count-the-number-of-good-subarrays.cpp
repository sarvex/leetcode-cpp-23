#include <unordered_map>
#include <vector>

class Solution {
  long long total = 0;
  long long ret = 0;

public:
  long long countGood(std::vector<int> &nums, int k) {
    int n = nums.size();
    int j = 0;
    std::unordered_map<int, int> count;

    for (int i = 0; i < n; i++) {
      while (j < n && total < k) {
        total += diff(count, nums[j], 1);
        count[nums[j]]++;
        j++;
      }
      if (total >= k)
        ret += n - j + 1;

      total += diff(count, nums[i], -1);
      count[nums[i]]--;
    }

    return ret;
  }

  long long diff(std::unordered_map<int, int> &count, int num, int d) {
    long long m = count[num];
    long long old = m * (m - 1) / 2;
    m += d;
    long long now = m * (m - 1) / 2;
    return now - old;
  }
};
