#include <unordered_set>
#include <vector>

class Solution
{
public:
  int findKthPositive(std::vector<int> &arr, int k)
  {
    std::unordered_set<int> Set(arr.begin(), arr.end());
    int count = 0;
    for (int i = 1; i <= arr.back() + 1000; i++)
    {
      if (Set.find(i) == Set.end())
        count += 1;
      if (count == k)
        return i;
    }
    return -1;
  }
};
