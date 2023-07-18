#include <vector>
class Solution
{
public:
  int waysToSplit(std::vector<int> &nums)
  {
    long long sum = accumulate(nums.begin(), nums.end(), 0);
    int n = nums.size();
    std::vector<long long> result(n);
    result[0] = nums[0];
    for (int i = 1; i < n; i++)
      result[i] = result[i - 1] + nums[i];

    long long ret = 0;
    long long M = 1e9 + 7;

    int left = 0, mid = 0, right = sum;
    int j = 0, k = n - 1;
    for (int i = 0; i < n; i++)
    {
      while (j <= i || (j < n && result[j] - result[i] < result[i]))
        j++;
      if (j == n)
        break;

      auto iter = upper_bound(result.begin(), result.end(), (sum + result[i]) / 2);
      int t = iter - result.begin() - 1;
      if (t == n - 1)
        t--;

      if (t < j)
        continue;

      ret += t - j + 1;
      ret %= M;
    }
    return ret;
  }
};
