#include <vector>

class Solution
{
public:
  long long maximumOr(std::vector<int> &nums, int k)
  {
    std::vector<int> count(32);

    for (int i = 0; i < nums.size(); i++)
    {
      for (int j = 0; j <= 31; j++)
      {
        if ((nums[i] >> j) & 1)
          count[j]++;
      }
    }

    long long ret = 0;
    for (int i = 0; i < nums.size(); i++)
    {
      auto temp = count;
      for (int j = 0; j <= 31; j++)
      {
        if ((nums[i] >> j) & 1)
          temp[j]--;
      }
      long long ans = 0;
      for (int j = 0; j <= 31; j++)
      {
        if (temp[j] > 0)
          ans += (1 << j);
      }
      ans |= ((long long)nums[i] << k);
      ret = max(ans, ret);
    }

    return ret;
  }
};
