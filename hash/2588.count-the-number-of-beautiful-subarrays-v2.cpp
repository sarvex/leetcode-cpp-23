#include <unordered_map>
#include <vector>

class Solution {
public:
  long long beautifulSubarrays(std::vector<int> &nums) {
    std::unordered_map<int, long long> Map;
    // Map[state] : how many times of state there have been
    Map[0] = 1;

    int state = 0;
    long long ret = 0;
    for (int i = 0; i < nums.size(); i++) {
      state = state ^ nums[i];
      ret += Map[state];
      Map[state] += 1;
    }

    return ret;
  }
};
