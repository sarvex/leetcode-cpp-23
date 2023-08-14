class Solution {
  const static long long M = 1e9 + 7;
  std::unordered_map<long long, long long> memo;

public:
  int countHousePlacements(int n) {
    long long ret = 0;
    for (int r = 0; 2 * r - 1 <= n; r++)
      ret = (ret + C(n - r + 1, r)) % M;
    return ret * ret % M;
  }

  long long C(int x, int y) {
    if (x < y) return 0;
    if (y == 0) return 1;
    if (y == 1) return x;

    if (memo.find(x * 10000 + y) != memo.end())
      return memo[x * 10000 + y];

    memo[x * 10000 + y] = (C(x - 1, y - 1) + C(x - 1, y)) % M;

    return memo[x * 10000 + y];
  }
};
