/**
 * @link https://leetcode.com/problems/kth-smallest-product-of-two-sorted-arrays/
 */
#include <algorithm>
#include <cmath>
#include <vector>

class Solution
{
public:
  long long kthSmallestProduct(std::vector<int> &nums1, std::vector<int> &nums2, long long k)
  {
    if (nums1.size() > nums2.size())
      return kthSmallestProduct(nums2, nums1, k);

    long long left = -1e10, right = 1e10;
    while (left < right)
    {
      long long mid = left + (right - left) / 2;
      if (checkNums(mid, nums1, nums2) >= k)
        right = mid;
      else
        left = mid + 1;
    }
    return left;
  }

  long long checkNums(long long mid, std::vector<int> &nums1, std::vector<int> &nums2)
  {
    long long ret = 0;
    for (int i = 0; i < nums1.size(); i++)
    {
      long long x = nums1[i];

      if (x == 0)
      {
        if (mid < 0)
          ret += 0;
        else
          ret += nums2.size();
      }
      else if (x > 0)
      {
        long long yy = floor(mid * 1.0 / x);
        auto iter = upper_bound(nums2.begin(), nums2.end(), yy);
        ret += (iter - nums2.begin());
      }
      else
      {
        long long yy = ceil(mid * 1.0 / x);
        auto iter = lower_bound(nums2.begin(), nums2.end(), yy);
        ret += nums2.size() - (iter - nums2.begin());
      }
    }

    return ret;
  }
};
