/**
 * @link https://leetcode.com/problems/minimize-the-maximum-of-two-arrays/
 */
#include <algorithm>
#include <numeric>

class Solution
{
public:
  int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2)
  {
    long long left = 1, right = std::numeric_limits<int>::max();
    while (left < right)
    {
      long long mid = left + (right - left) / 2;
      if (NotEnough(divisor1, divisor2, uniqueCnt1, uniqueCnt2, mid))
        left = mid + 1;
      else
        right = mid;
    }
    return left;
  }

  bool NotEnough(long long divisor1, long long divisor2, long long uniqueCnt1, long long uniqueCnt2, long long n)
  {
    long long a = n - n / divisor1;
    long long b = n - n / divisor2;
    long long c = n - (n / divisor1 + n / divisor2 - n / std::lcm(divisor1, divisor2));

    if (a < uniqueCnt1)
      return true;
    if (b < uniqueCnt2)
      return true;
    if (a + b - c < uniqueCnt1 + uniqueCnt2)
      return true;
    return false;
  }
};
