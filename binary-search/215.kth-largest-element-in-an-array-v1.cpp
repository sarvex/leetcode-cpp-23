#include <limits>
#include <vector>

class Solution
{
public:
  int findKthLargest(std::vector<int> &nums, int k)
  {
    long left = std::numeric_limits<int>::min(), right = std::numeric_limits<int>::max();
    while (left < right)
    {
      int mid = right - (right - left) / 2;
      if (count(nums, mid) >= k)
        left = mid;
      else
        right = mid - 1;
    }
    return left;
  }

  int count(std::vector<int> &nums, int t)
  {
    int ret = 0;
    for (auto x : nums)
      ret += (x >= t);
    return ret;
  }
};
