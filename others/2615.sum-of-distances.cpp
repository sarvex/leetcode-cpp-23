#include <unordered_map>
#include <vector>

class Solution {
public:
  std::vector<long long> distance(std::vector<int> &nums) {
    int n = nums.size();
    unordered_map<int, std::vector<long long>> Map;
    for (int i = 0; i < nums.size(); i++)
      Map[nums[i]].push_back(i);

    std::unordered_map<int, long long> ans;
    std::unordered_map<int, long long> idx;
    for (auto &[k, v]: Map) {
      idx[k] = 0;
      long long sum = 0;
      for (int p: v)
        sum += abs(p - v[0]);
      ans[k] = sum;
    }


    std::vector<long long> rets;
    for (int x: nums) {
      rets.push_back(ans[x]);
      int i = idx[x];
      if (i == Map[x].size() - 1) continue;
      long long temp = ans[x];
      int m = Map[x].size();
      temp += (Map[x][i + 1] - Map[x][i]) * (i + 1);
      temp -= (Map[x][i + 1] - Map[x][i]) * (m - 1 - i);
      ans[x] = temp;
      idx[x] = i + 1;
    }

    return rets;
  }
};
