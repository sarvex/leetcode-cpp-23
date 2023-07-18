#include <limits>

class Solution
{
public:
  int nthUglyNumber(int n, int a, int b, int c)
  {
    long long left = 1;
    long long right = INT_MAX;

    while (left < right)
    {
      long long mid = left + (right - left) / 2;
      if (count(mid, a, b, c) < n)
        left = mid + 1;
      else
        right = mid;
    }

    return left;
  }

  int count(long long M, long long a, long long b, long long c)
  {
    return M / a + M / b + M / c - M / lcm(a, b) - M / lcm(a, c) - M / lcm(b, c) + M / lcm(lcm(a, b), c);
  }

  long long lcm(long long a, long long b)
  {
    return a * b / gcd(a, b);
  }

  long long gcd(long long a, long long b)
  {
    if (b == 0)
      return a;
    return gcd(b, a % b);
  }
};
