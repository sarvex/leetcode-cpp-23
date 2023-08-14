/**
 * @link https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
 */
#include <vector>

class Solution
{
public:
  int findMin(std::vector<int> &nums)
  {
    int i = 0, j = nums.size() - 1;
    if (nums[j] >= nums[i])
      return nums[i];

    while (i < j)
    {
      int k = i + (j - i) / 2;
      if (nums[k] >= nums[0])
        i = k + 1;
      else
        j = k;
    }
    return nums[i];
  }
};
