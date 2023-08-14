#include <algorithm>
#include <stack>
#include <vector>

class Solution {
public:
  long long maximumBooks(std::vector<int> &books) {
    int n = books.size();
    std::vector<long long> dp(n);
    std::stack<long long> stk;

    long long ret = 0;
    for (int i = 0; i < n; i++) {
      while (!stk.empty() && books[stk.top()] > books[i] - (i - stk.top()))
        stk.pop();

      if (!stk.empty()) {
        long long d = i - stk.top();
        dp[i] = dp[stk.top()] + ((long long) books[i] + (long long) books[i] - d + 1) * d / 2;
      } else {
        long long d = std::min(i + 1, books[i]);
        dp[i] = ((long long) books[i] + (long long) books[i] - d + 1) * d / 2;
      }
      stk.push(i);

      ret = std::max(ret, dp[i]);
    }

    return ret;
  }
};
