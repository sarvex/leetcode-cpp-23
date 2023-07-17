/**
 * @link https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs
 */
#include <algorithm>
#include <vector>

class Solution
{
public:
  int minimizeMax(std::vector<int> &nums, int p)
  {
    std::sort(nums.begin(), nums.end());
    int left = 0, right = INT_MAX;
    while (left < right)
    {
      int mid = left + (right - left) / 2;
      if (isOK(nums, p, mid))
        right = mid;
      else
        left = mid + 1;
    }
    return left;
  }

  bool isOK(std::vector<int> &nums, int p, int diff)
  {
    int n = nums.size();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
      if (i + 1 < n && nums[i + 1] - nums[i] <= diff)
      {
        count++;
        i = i + 1;
      }
    }
    return (count >= p);
  }
};
