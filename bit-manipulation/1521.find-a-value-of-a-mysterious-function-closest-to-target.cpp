#include <vector>

class Solution {
public:
  int closestToTarget(vector<int> &arr, int target) {
    unordered_set<int> s;
    int ret = std::numeric_limits<int>::max();
    for (int i = 0; i < arr.size(); i++) {
      unordered_set<int> s2;
      for (auto x: s)
        s2.insert(x & arr[i]);
      s2.insert(arr[i]);
      for (auto x: s2)
        ret = min(ret, abs(x - target));
      s = s2;
    }
    return ret;
  }
};
