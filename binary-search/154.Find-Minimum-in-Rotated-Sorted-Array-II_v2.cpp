/**
 * @link https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii
 */
#include <vector>
using std::vector;

class Solution
{
public:
  int findMin(vector<int> &nums)
  {
    int left = 0;
    int right = nums.size() - 1;

    while (left < right)
    {
      int mid = left + (right - left) / 2;
      if (nums[mid] > nums[right])
        left = mid + 1;
      else if (nums[mid] < nums[right])
        right = mid;
      else
        right -= 1;
    }
    return nums[left];
  }
};
