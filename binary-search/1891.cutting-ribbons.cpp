/**
 * @link https://leetcode.com/problems/cutting-ribbons/
 */
#include <limits>
#include <vector>

class Solution
{
public:
  int maxLength(std::vector<int> &ribbons, int k)
  {
    int left = 0, right = std::numeric_limits<int>::max();
    while (left < right)
    {
      int len = right - (right - left) / 2;
      if (count(ribbons, len) >= k)
        left = len;
      else
        right = len - 1;
    }
    return left;
  }

  int count(std::vector<int> &ribbons, int len)
  {
    int ret = 0;
    for (auto x : ribbons)
    {
      ret += x / len;
    }
    return ret;
  }
};
