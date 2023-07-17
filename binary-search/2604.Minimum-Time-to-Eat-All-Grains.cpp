/**
 * @link https://leetcode.com/problems/minimum-time-to-eat-all-grains/
 */
#include <algorithm>
#include <limits>
#include <vector>

class Solution
{
public:
  int minimumTime(std::vector<int> &hens, std::vector<int> &grains)
  {
    sort(hens.begin(), hens.end());
    sort(grains.begin(), grains.end());

    int left = 0, right = std::numeric_limits<int>::max() / 2;
    while (left < right)
    {
      int mid = left + (right - left) / 2;
      if (isOK(mid, hens, grains))
        right = mid;
      else
        left = mid + 1;
    }
    return left;
  }

  bool isOK(int time, std::vector<int> &hens, std::vector<int> &grains)
  {
    int j = 0;
    for (int i = 0; i < hens.size(); i++)
    {
      int t;
      if (grains[j] < hens[i])
      {
        if (grains[j] < hens[i] - time)
          return false;
        t = (hens[i] - grains[j]);
      }
      else
      {
        t = 0;
      }

      while (j < grains.size() && grains[j] <= hens[i])
        j++;

      if (time < 3 * t)
      {
        while (j < grains.size() && (grains[j] - hens[i]) * 2 + t <= time)
          j++;
      }
      else
      {
        while (j < grains.size() && (grains[j] - hens[i]) + t * 2 <= time)
          j++;
      }

      if (j == grains.size())
        return true;
    }

    return false;
  }
};
