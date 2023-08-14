#include <algorithm>
#include <array>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
public:
  std::vector<std::vector<long long>> splitPainting(std::vector<std::vector<int>> &segments) {
    std::vector<std::array<long long, 3>> arr;
    for (auto seg: segments) {
      arr.push_back({seg[0], 1, seg[2]});
      arr.push_back({seg[1], -1, seg[2]});
    }

    std::sort(arr.begin(), arr.end());

    std::unordered_set<long long> Set;
    long long sum = 0;
    long long start = -1, end = -1;

    std::vector<std::vector<long long>> rets;

    for (int i = 0; i < arr.size(); i++) {
      int j = i;

      std::unordered_map<long long, long long> Map;
      while (j < arr.size() && arr[j][0] == arr[i][0]) {
        if (arr[j][1] == 1)
          Map[arr[j][2]]++;
        else
          Map[arr[j][2]]--;

        j++;
      }

      int flag = 0;
      for (auto x: Map)
        if (x.second != 0) {
          flag = 1;
          break;
        }

      if (flag == 0) {
        if (!rets.empty() && !Set.empty())
          rets.back()[1] = arr[i][0];

        i = j - 1;
        continue;
      }

      if (start == -1) {
        start = arr[i][0];
      } else {
        end = arr[i][0];
        rets.push_back({start, end, sum});
        start = end;
      }

      for (auto x: Map) {
        auto [color, freq] = x;

        if (freq > 0 && Set.find(color) == Set.end()) {
          Set.insert(color);
          sum += color;
        } else if (freq < 0) {
          Set.erase(color);
          sum -= color;
        }
      }

      if (Set.empty())
        start = -1;

      i = j - 1;
    }

    return rets;
  }
};
