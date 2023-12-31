/**
 * @link https://leetcode.com/problems/median-of-two-sorted-arrays
 */
#include <queue>
#include <utility>
#include <vector>

class Solution
{
  struct cmp
  {
    bool operator()(std::pair<int, int> a, std::pair<int, int> b)
    {
      return a.first > b.first;
    }
  };

public:
  double findMedianSortedArrays(std::vector<int> &nums1, std::vector<int> &nums2)
  {
    int m = nums1.size();
    int n = nums2.size();
    if ((m + n) % 2 == 0)
      return 0.5f * (findKth(nums1, nums2, (m + n) / 2) + findKth(nums1, nums2, (m + n) / 2 + 1));
    else
      return findKth(nums1, nums2, (m + n) / 2 + 1);
  }

  double findKth(std::vector<int> nums1, std::vector<int> nums2, int k)
  {
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, cmp> q;
    int count = 0;
    int i = 0;
    int j = 0;
    if (nums1.size() != 0)
    {
      q.push({nums1[0], 1});
      i++;
    }
    if (nums2.size() != 0)
    {
      q.push({nums2[0], 2});
      j++;
    }

    int result;
    while (count < k)
    {
      int label = q.top().second;
      result = q.top().first;
      q.pop();
      count++;
      if (label == 1 && i < nums1.size())
      {
        q.push({nums1[i], 1});
        i++;
      }
      else if (label == 2 && j < nums2.size())
      {
        q.push({nums2[j], 2});
        j++;
      }
    }
    return result;
  }
};
