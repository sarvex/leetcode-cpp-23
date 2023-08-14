#include <set>
#include <vector>

class Solution {
public:
  std::vector<int> maxSlidingWindow(std::vector<int> &nums, int k) {
    std::vector<int> results;
    std::multiset<int> Set;

    for (int i = 0; i < nums.size(); i++) {
      Set.insert(nums[i]);
      if (Set.size() > k)
        Set.erase(Set.lower_bound(nums[i - k]));

      if (Set.size() < k) continue;
      results.push_back(*Set.rbegin());
    }

    return results;
  }
};
