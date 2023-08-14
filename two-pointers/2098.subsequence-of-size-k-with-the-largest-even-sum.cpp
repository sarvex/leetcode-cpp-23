#include <algorithm>
#include <vector>

class Solution {
public:
  long long largestEvenSum(std::vector<int> &nums, int k) {
    std::vector<int> odd;
    std::vector<int> even;
    for (int x: nums) {
      if (x % 2 == 0) even.push_back(x);
      if (x % 2 == 1) odd.push_back(x);
    }
    std::sort(odd.rbegin(), odd.rend());
    std::sort(even.rbegin(), even.rend());

    int m = odd.size();
    std::vector<long long> prefix1(m + 1);
    for (int i = 1; i <= m; i++)
      prefix1[i] = prefix1[i - 1] + odd[i - 1];

    int n = even.size();
    std::vector<long long> prefix2(n + 1);
    for (int i = 1; i <= n; i++)
      prefix2[i] = prefix2[i - 1] + even[i - 1];

    long long ret = -1;
    int j = even.size();
    for (int i = 0; i <= std::min(k, (int) odd.size()); i++) {
      while (i + j > k) j--;
      if (j < 0) break;
      if (i + j == k && (prefix1[i] + prefix2[j]) % 2 == 0)
        ret = std::max(ret, prefix1[i] + prefix2[j]);
    }

    return ret;
  }
};
