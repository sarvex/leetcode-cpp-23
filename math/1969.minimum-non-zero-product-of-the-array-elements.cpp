class Solution {
  const static long long M = 1e9 + 7;

public:
  long long quickMul(long long x, long long N) {
    if (N == 0) return 1;
    long long y = quickMul(x, N / 2);
    return N % 2 == 0 ? (y * y % M) : (y * y % M * x % M);
  }

  int minNonZeroProduct(int p) {
    long long a = (1ll << (p - 1)) - 1;
    long long x = ((1ll << p) - 1) % M;
    long long ret = quickMul(x - 1, a) * x % M;

    return ret;
  }
};
