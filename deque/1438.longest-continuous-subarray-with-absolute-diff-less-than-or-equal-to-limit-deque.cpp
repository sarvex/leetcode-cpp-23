#include <algorithm>
#include <deque>
#include <vector>

class Solution {
public:
  int longestSubarray(std::vector<int> &nums, int limit) {
    std::deque<int> qmax({0});
    std::deque<int> qmin({0});

    int j = 0;
    int ret = 1;
    int mx = nums[0], mn = nums[0];
    for (int i = 0; i < nums.size() && j < nums.size(); i++) {
      while (mx - mn <= limit) {
        ret = std::max(ret, j - i + 1);
        j++;
        if (j >= nums.size()) break;

        while (qmax.size() > 0 && nums[j] >= nums[qmax.back()])
          qmax.pop_back();
        qmax.push_back(j);
        mx = nums[qmax.front()];

        while (qmin.size() > 0 && nums[j] <= nums[qmin.back()])
          qmin.pop_back();
        qmin.push_back(j);
        mn = nums[qmin.front()];
      }

      if (j >= nums.size()) break;

      if (qmax.size() > 0 && qmax.front() <= i) {
        qmax.pop_front();
        mx = nums[qmax.front()];
      }
      if (qmin.size() > 0 && qmin.front() <= i) {
        qmin.pop_front();
        mn = nums[qmin.front()];
      }
    }
    return ret;
  }
};
