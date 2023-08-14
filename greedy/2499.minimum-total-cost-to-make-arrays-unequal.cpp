#include <algorithm>
#include <unordered_map>
#include <vector>

class Solution {
public:
  long long minimumTotalCost(std::vector<int> &nums1, std::vector<int> &nums2) {
    int n = nums1.size();
    std::unordered_map<int, int> count;
    int total = 0;
    long long ret = 0;
    for (int i = 0; i < n; i++) {
      if (nums1[i] == nums2[i]) {
        count[nums1[i]]++;
        total++;
        ret += i;
      }
    }

    int maxCount = 0;
    for (auto &[k, v]: count)
      maxCount = std::max(maxCount, v);

    int maxVal;
    for (auto &[val, freq]: count)
      if (freq == maxCount)
        maxVal = val;

    if (maxCount <= total - maxCount)
      return ret;

    int extra = maxCount - (total - maxCount);
    for (int i = 0; i < n; i++) {
      if (extra == 0) break;
      if (nums1[i] == nums2[i]) continue;
      if (nums1[i] == maxVal || nums2[i] == maxVal) continue;
      extra--;
      ret += i;
    }

    if (extra == 0)
      return ret;
    else
      return -1;
  }
};
