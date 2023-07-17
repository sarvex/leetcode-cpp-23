/**
 * @link https://leetcode.com/problems/divide-two-integers
 */
#include <algorithm>
#include <limits>

class Solution
{
public:
  int divide(int dividend, int divisor)
  {
    if (divisor == 0)
      return std::numeric_limits<int>::max();
    if (dividend == 0)
      return 0;

    long long a = std::abs((long long)dividend);
    long long b = std::abs((long long)divisor);
    long long c;
    long long sum = 0;

    int sign = 1;
    if (divisor < 0)
      sign *= -1;
    if (dividend < 0)
      sign *= -1;

    while (a >= b)
    {
      c = b;
      long long count = 1;
      while ((c << 1) <= a)
      {
        c = c << 1;
        count = count << 1;
      }
      sum += count;
      a = a - c;
    }

    sum = sum * sign;

    if (sum > INT_MAX)
      return INT_MAX;
    else
      return sum;
  }
};
