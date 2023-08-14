#include <algorithm>
#include <unordered_set>
#include <vector>

class Solution {
public:
  long long countExcellentPairs(std::vector<int> &nums, int k) {
    std::vector<int> arr;
    std::unordered_set<int> Set(nums.begin(), nums.end());

    long long ret = 0;
    for (auto x: Set) {
      arr.push_back(__builtin_popcount(x));
    }

    std::sort(arr.begin(), arr.end());

    long long n = arr.size();
    long long j = n - 1;
    for (int i = 0; i < n; i++) {
      while (j >= 0 && arr[i] + arr[j] >= k)
        j--;
      if (j >= i)
        ret += n - (j + 1);
      else
        ret += n - (i + 1);
    }
    ret *= 2;

    for (auto x: arr) {
      if (x * 2 >= k)
        ret++;
    }

    return ret;
  }
};
