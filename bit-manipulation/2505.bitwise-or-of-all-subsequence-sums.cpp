#include <vector>

class Solution
{
public:
  long long subsequenceSumOr(vector<int> &nums)
  {
    long long ret = 0;
    long long sum = 0;
    for (int x : nums)
    {
      ret = ret | x;
      sum += x;
      ret = ret | sum;
    }
    return ret;
  }
};
