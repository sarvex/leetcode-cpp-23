#include <numeric>
#include <vector>

class Solution {
public:
  long long numberOfWeeks(std::vector<int> &milestones) {
    long long sum = std::accumulate(milestones.begin(), milestones.end(), 0LL);
    long long mx = *std::max_element(milestones.begin(), milestones.end());
    if (mx <= sum / 2) return sum;
    else
      return (sum - mx) * 2 + 1;
  }
};
