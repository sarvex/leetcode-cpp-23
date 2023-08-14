class Solution {
  long long comb[1005][1005];
  const static long long M = 1e9 + 7;

public:
  int numberOfWays(int startPos, int endPos, int k) {
    int diff = abs(endPos - startPos);
    if (diff > k) return 0;

    if ((diff + k) % 2 == 1) return 0;

    int a = (k + diff) / 2;
    int b = (k - diff) / 2;

    return C(k, a);
  }

  long long C(int m, int n) {
    if (comb[m][n] != 0) return comb[m][n];
    if (n == 0) return 1;
    if (m == n) return 1;

    long long ret = C(m - 1, n - 1) + C(m - 1, n);
    comb[m][n] = ret % M;

    return comb[m][n];
  }
};
