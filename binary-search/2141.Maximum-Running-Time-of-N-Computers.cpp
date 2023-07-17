/**
 * @link https://leetcode.com/problems/maximum-running-time-of-n-computers/
 */
#include <algorithm>
#include <limits>
#include <vector>

class Solution
{
public:
  long long maxRunTime(int n, std::vector<int> &batteries)
  {
    long long left = 0, right = std::numeric_limits<long long>::max() / n;
    while (left < right)
    {
      long long mid = right - (right - left) / 2;
      if (checkOK(mid, n, batteries))
        left = mid;
      else
        right = mid - 1;
    }
    return left;
  }

  bool checkOK(long long T, long long n, std::vector<int> &batteries)
  {
    long long sum = 0;
    for (auto x : batteries)
    {
      sum += std::min((long long)x, T);
      if (sum >= T * n)
        return true;
    }
    return false;
  }
};
