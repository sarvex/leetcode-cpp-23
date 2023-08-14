#include <string>
#include <vector>

class Solution {
  const static long long M = 1e9 + 7;

public:
  int count(std::string num1, std::string num2, int min_sum, int max_sum) {
    long long ret = (CountNoGreater(num2, max_sum) - CountNoGreater(num2, min_sum - 1) + M) % M - (CountNoGreater(num1, max_sum) - CountNoGreater(num1, min_sum - 1) + M) % M;

    ret = (ret + M) % M;

    int digitSum = calculate(num1);
    if (digitSum >= min_sum && digitSum <= max_sum) ret = (ret + 1) % M;
    return ret;
  }

  int calculate(std::string &s) {
    int ret = 0;
    for (auto ch: s) ret += ch - '0';
    return ret;
  }

  long long CountNoGreater(std::string num, int max_sum) {
    std::vector<std::vector<std::vector<int>>> memo(2, std::vector<std::vector<int>>(25, std::vector<int>(405, -1)));
    return dfs(num, max_sum, 0, 0, true, memo);
  }

  long long dfs(std::string num, int max_sum, int i, int sum, bool isSame, std::vector<std::vector<std::vector<int>>> &memo) {
    if (sum > max_sum) return 0;
    if (memo[isSame][i][sum] != -1) return memo[isSame][i][sum];
    if (i == num.size()) return 1;

    long long ret = 0;
    if (!isSame) {
      for (int k = 0; k <= 9; k++) {
        ret += dfs(num, max_sum, i + 1, sum + k, false, memo);
        ret %= M;
      }
    } else {
      for (int k = 0; k < (num[i] - '0'); k++) {
        ret += dfs(num, max_sum, i + 1, sum + k, false, memo);
        ret %= M;
      }
      ret += dfs(num, max_sum, i + 1, sum + (num[i] - '0'), true, memo);
      ret %= M;
    }

    memo[isSame][i][sum] = ret;
    return ret;
  }
};
