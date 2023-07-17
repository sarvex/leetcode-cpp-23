/**
 * @link https://leetcode.com/problems/count-the-number-of-fair-pairs/
 */
#include <algorithm>
#include <vector>

class Solution
{
public:
  long long countFairPairs(std::vector<int> &nums, int lower, int upper)
  {
    std::sort(nums.begin(), nums.end());

    long long ret = 0;
    for (int x : nums)
    {
      int k = std::upper_bound(nums.begin(), nums.end(), upper - x) - nums.begin();
      int t = std::lower_bound(nums.begin(), nums.end(), lower - x) - nums.begin();
      int count = k - t;

      if (x + x <= upper && x + x >= lower)
        count--;

      ret += count;
    }

    return ret / 2;
  }
};
