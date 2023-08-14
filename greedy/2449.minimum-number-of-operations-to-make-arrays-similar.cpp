#include <algorithm>
#include <vector>

class Solution {
public:
  long long makeSimilar(std::vector<int> &nums, std::vector<int> &target) {
    std::vector<long long> odd1, odd2, even1, even2;
    for (auto x: nums) {
      if (x % 2 == 0)
        even1.push_back(x);
      else
        odd1.push_back(x);
    }
    for (auto x: target) {
      if (x % 2 == 0)
        even2.push_back(x);
      else
        odd2.push_back(x);
    }

    return helper(even1, even2) + helper(odd1, odd2);
  }

  long long helper(std::vector<long long> &nums, std::vector<long long> &target) {
    std::sort(target.begin(), target.end());
    std::sort(nums.begin(), nums.end());

    long long count = 0;
    for (int i = 0; i < nums.size(); i++)
      if (nums[i] > target[i])
        count += (nums[i] - target[i]) / 2;

    return count;
  }
};
