#include <algorithm>
#include <unordered_map>
#include <vector>

class Solution {
public:
  long long maximumSubarraySum(std::vector<int> &nums, int k) {
    long long ret = 0;
    std::unordered_map<int, int> Map;
    int count = 0;
    long long sum = 0;
    for (int i = 0; i < nums.size(); i++) {
      Map[nums[i]]++;
      if (Map[nums[i]] == 1)
        count++;
      sum += nums[i];

      if (i >= k - 1) {
        if (count == k)
          ret = std::max(ret, sum);

        Map[nums[i - k + 1]]--;
        sum -= nums[i - k + 1];
        if (Map[nums[i - k + 1]] == 0)
          count--;
      }
    }

    return ret;
  }
};
