#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <vector>

class Solution {
public:
  int beautifulSubsets(std::vector<int> &nums, int k) {
    std::unordered_map<int, int> count;
    for (int x: nums)
      count[x] += 1;

    std::unordered_map<int, std::vector<pair<int, int>>> Map;
    for (auto [val, count]: count)
      Map[val % k].push_back({val, count});

    int ret = 1;
    for (auto &[r, arr]: Map) {
      std::sort(arr.begin(), arr.end());

      int take = 0, notake = 1;
      for (int i = 0; i < arr.size(); i++) {
        int notake_temp = notake;
        int take_temp = take;
        if (i != 0 && arr[i].first == arr[i - 1].first + k) {
          take = notake_temp * (std::pow(2, arr[i].second) - 1);
          notake = (take_temp + notake_temp) * 1;
        } else {
          take = (take_temp + notake_temp) * (std::pow(2, arr[i].second) - 1);
          notake = (take_temp + notake_temp) * 1;
        }
      }
      ret *= (take + notake);
    }
    return ret - 1;
  }
};
