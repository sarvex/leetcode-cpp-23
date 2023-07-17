/**
 * @link https://leetcode.com/problems/maximum-candies-allocated-to-k-children/
 */
#include <vector>

class Solution
{
public:
  int maximumCandies(std::vector<int> &candies, long long k)
  {
    long long total = 0;
    for (auto x : candies)
      total += (long long)x;

    long long left = 0, right = total / k;
    while (left < right)
    {
      long long mid = right - (right - left) / 2;
      if (checkOK(candies, mid, k))
        left = mid;
      else
        right = mid - 1;
    }
    return left;
  }

  bool checkOK(std::vector<int> &candies, long long numPerPile, long long k)
  {
    long long count = 0;
    for (long long x : candies)
    {
      count += x / numPerPile;
      if (count >= k)
        return true;
    }
    return false;
  }
};
