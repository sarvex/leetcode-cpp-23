#include <vector>

class Solution
{
public:
  int waysToSplit(std::vector<int> &nums)
  {
    int n = nums.size();
    std::vector<long long> result(n, 0);
    result[0] = nums[0];
    for (int i = 1; i < n; i++)
      result[i] = result[i - 1] + nums[i];

    int j = 0, k = 0;
    long long ret = 0;
    long long M = 1e9 + 7;
    for (int i = 0; i < n; i++)
    {
      while (j <= i || (j < n && result[j] - result[i] < result[i]))
        j++;
      if (j == n)
        break;

      while (k + 1 < n - 1 && result[k + 1] * 2 <= result[i] + result[n - 1])
        k += 1;

      if (k < j)
        continue;

      ret += k - j + 1;
      ret %= M;
    }
    return ret;
  }
};
