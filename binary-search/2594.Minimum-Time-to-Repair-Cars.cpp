/**
 * @link https://leetcode.com/problems/minimum-time-to-repair-cars/
 */
#include <algorithm>
#include <cmath>
#include <limits>
#include <vector>

class Solution
{
public:
  long long repairCars(std::vector<int> &ranks, int cars)
  {
    long long left = 0, right = std::numeric_limits<long long>::max();
    while (left < right)
    {
      long long mid = left + (right - left) / 2;
      if (isOK(mid, ranks, cars))
        right = mid;
      else
        left = mid + 1;
    }
    return left;
  }

  bool isOK(long long t, std::vector<int> &ranks, int cars)
  {
    long long count = 0;
    for (int r : ranks)
    {
      count += sqrt(t / r);
      if (count >= cars)
        return true;
    }
    return false;
  }
};
