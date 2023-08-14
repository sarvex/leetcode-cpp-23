#include <limits>
#include <vector>

class Solution
{
public:
  std::vector<std::vector<int>> kSmallestPairs(std::vector<int> &nums1, std::vector<int> &nums2, int k)
  {
    long left = std::numeric_limits<int>::min(), right = std::numeric_limits<int>::max();
    while (left < right)
    {
      long mid = left + (right - left) / 2;
      long count = countSmallerOrEqual(mid, nums1, nums2);
      if (count < k)
        left = mid + 1;
      else
        right = mid;
    }
    int m = left;

    // TODO-TLE: nums1 = [1] * 100000, nums2 = [1] * 100000, k = 2
    std::vector<std::vector<int>> rets;
    for (int i = 0; i < nums1.size(); i++)
    {
      for (int j = 0; j < nums2.size() && nums1[i] + nums2[j] < m; j++)
      {
        rets.push_back({nums1[i], nums2[j]});
      }
    }

    // 316ms/11.89% -> 148ms/43.01%
    for (int i = 0; i < nums1.size(); i++)
    {
      for (int j = 0; j < nums2.size() && nums1[i] + nums2[j] <= m && rets.size() < k; j++)
      {
        if (nums1[i] + nums2[j] == m)
        {
          rets.push_back({nums1[i], nums2[j]});
        }
      }
    }

    return rets;
  }

  long countSmallerOrEqual(int m, std::vector<int> &nums1, std::vector<int> &nums2)
  {
    int j = nums2.size() - 1;
    long ret = 0;
    for (int i = 0; i < nums1.size(); i++)
    {
      while (j >= 0 && nums1[i] + nums2[j] > m)
        j--;
      ret += j + 1;
    }
    return ret;
  }
};
