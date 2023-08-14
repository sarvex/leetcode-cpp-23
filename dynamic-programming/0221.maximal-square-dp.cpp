#include <algorithm>
#include <vector>

class Solution {
public:
  int maximalSquare(std::vector<std::vector<char>> &matrix) {
    int M = matrix.size();
    if (M == 0) return 0;
    int N = matrix[0].size();
    auto dp = std::vector<std::vector<int>>(M + 1, std::vector<int>(N + 1, 0));
    int result = 0;

    for (int i = 1; i <= M; i++)
      for (int j = 1; j <= N; j++) {
        if (matrix[i - 1][j - 1] == '0')
          dp[i][j] = 0;
        else {
          int temp = std::min(dp[i - 1][j], dp[i][j - 1]);
          temp = std::min(temp, dp[i - 1][j - 1]);
          dp[i][j] = temp + 1;
          result = std::max(result, dp[i][j] * dp[i][j]);
        }
      }

    return result;
  }
};
