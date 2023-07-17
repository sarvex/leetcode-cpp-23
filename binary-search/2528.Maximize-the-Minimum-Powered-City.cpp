/**
 * @link https://leetcode.com/problems/maximize-the-minimum-powered-city/
 */
#include <algorithm>
#include <limits>
#include <vector>

class Solution
{
public:
  long long maxPower(std::vector<int> &stations, int r, int k)
  {
    long long left = 0, right = std::numeric_limits<long long>::max();
    while (left < right)
    {
      long long mid = right - (right - left) / 2;
      if (isOK(stations, r, k, mid))
        left = mid;
      else
        right = mid - 1;
    }
    return left;
  }

  bool isOK(std::vector<int> stations, int r, long long k, long long m)
  {
    int n = stations.size();
    long long sum = 0;
    for (int i = 0; i <= std::min(n - 1, r - 1); i++)
      sum += stations[i];

    for (int i = 0; i < n; i++)
    {
      if (i + r < n)
        sum += stations[i + r];

      if (i - r - 1 >= 0)
        sum -= stations[i - r - 1];

      if (sum >= m)
        continue;

      long long diff = m - sum;
      if (diff > k)
        return false;
      stations[std::min(n - 1, i + r)] += diff;
      sum = m;
      k -= diff;
    }
    return true;
  }
};
