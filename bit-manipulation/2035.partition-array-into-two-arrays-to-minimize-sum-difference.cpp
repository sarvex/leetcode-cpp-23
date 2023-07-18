#include <limits>
#include <vector>

class Solution
{
public:
  unordered_map<int, vector<long long>> helper(vector<int> &nums)
  {
    unordered_map<int, vector<long long>> Map;
    int n = nums.size();
    for (int state = 0; state < (1 << n); state++)
    {
      long long sum = 0;
      int k = __builtin_popcount(state);
      for (int i = 0; i < n; i++)
      {
        if ((state >> i) & 1)
          sum += (long long)nums[i];
      }
      Map[k].push_back(sum);
    }
    for (auto &x : Map)
      sort(x.second.begin(), x.second.end());
    return Map;
  }

  int minimumDifference(vector<int> &nums)
  {
    int n = nums.size() / 2;
    vector<int> nums1;
    vector<int> nums2;
    for (int i = 0; i < n; i++)
      nums1.push_back(nums[i]);
    for (int i = n; i < 2 * n; i++)
      nums2.push_back(nums[i]);

    unordered_map<int, vector<long long>> Map2 = helper(nums2);

    long long sum = accumulate(nums.begin(), nums.end(), 0long long);
    long long ret = std::numeric_limits<long long>::max();

    for (int state = 0; state < (1 << n); state++)
    {
      long long x = 0;
      int i = __builtin_popcount(state);
      for (int k = 0; k < n; k++)
      {
        if ((state >> k) & 1)
          x += (long long)nums1[k];
      }
      int j = n - i;
      auto iter = lower_bound(Map2[j].begin(), Map2[j].end(), sum / 2 - x);
      if (iter != Map2[j].end())
        ret = min(ret, abs(*iter * 2 + 2 * x - sum));
      if (iter != Map2[j].begin())
      {
        iter = prev(iter);
        ret = min(ret, abs(*iter * 2 + 2 * x - sum));
      }
    }
    return ret;
  }
};
