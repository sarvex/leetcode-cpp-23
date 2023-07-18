#include <algorithm>
#include <vector>

class Solution
{
public:
  int specialArray(std::vector<int> &nums)
  {
    int N = nums.size();
    std::vector<int> freq(N + 1, 0);
    for (auto x : nums)
      freq[std::min(x, N)] += 1;

    int count = 0;
    for (int x = N; x >= 0; x--)
    {
      count += freq[x];
      if (count == x)
        return x;
    }
    return -1;
  }
};
