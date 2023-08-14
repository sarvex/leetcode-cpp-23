#include <unordered_map>
#include <vector>

class Solution {
public:
  std::vector<long long> getDistances(std::vector<int> &arr) {
    std::unordered_map<int, std::vector<long long>> Map;
    for (int i = 0; i < arr.size(); i++)
      Map[arr[i]].push_back(i);

    std::unordered_map<int, std::vector<long long>> rets;
    for (auto x: Map) {
      int val = x.first;
      auto pos = x.second;
      int n = pos.size();

      long long sum0 = 0;
      long long sum1 = 0;
      for (int i = 1; i < n; i++)
        sum1 += abs(pos[i] - pos[0]);
      rets[val].push_back(sum0 + sum1);

      for (int i = 1; i < n; i++) {
        sum0 += i * (pos[i] - pos[i - 1]);
        sum1 -= (n - i) * (pos[i] - pos[i - 1]);
        rets[val].push_back(sum0 + sum1);
      }
    }

    std::vector<long long> ans;
    std::unordered_map<int, int> index;
    for (auto x: arr) {
      int idx = index[x];
      ans.push_back(rets[x][idx]);
      index[x] += 1;
    }
    return ans;
  }
};
