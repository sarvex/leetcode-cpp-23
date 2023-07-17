/**
 * @link https://leetcode.com/problems/kth-smallest-subarray-sum/
 */
#include <limits>
#include <vector>

class Solution
{
public:
  int kthSmallestSubArraySum(std::vector<int> &nums, int k)
  {
    std::vector<int> result(nums.size() + 1);
    for (int i = 0; i < nums.size(); i++)
      result[i + 1] = result[i] + nums[i];

    int left = 0, right = std::numeric_limits<int>::max();
    while (left < right)
    {
      int mid = left + (right - left) / 2;

      int count = countSmallerOrEqual(mid, result); // # of diff <= mid

      if (count >= k)
        right = mid;
      else
        left = mid + 1;
    }
    return left;
  }

  int countSmallerOrEqual(int t, std::vector<int> &result)
  {
    int ret = 0;
    // for (int i=0; i<result.size(); i++)
    // {
    //     auto iter = upper_bound(result.begin(), result.end(), t+result[i]);
    //     ret += iter - (result.begin()+i+1);
    // }
    int j = 0;
    for (int i = 0; i < result.size(); i++)
    {
      while (j < result.size() && result[j] - result[i] <= t)
        j++;
      ret += j - (i + 1);
    }
    return ret;
  }
};
