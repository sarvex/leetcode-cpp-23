const long long N = 1e6 + 7, mod = 998244353;

/*********************************/
// Linear method to compute inv[i]
int main() {
  long long inv[N];
  inv[1] = 1;
  for (int i = 2; i < N; ++i)
    inv[i] = (mod - mod / i) * inv[mod % i] % mod;

  // ret *= inv[n] % mod;   // ret = (ret / n) % mod;
}

/*********************************/
// Qucik Pow Method, based on Fermat's little theorem

long long quickPow(int x, int y) {
  long long ret = 1;
  long long cur = x;
  while (y) {
    if (y & 1) {
      ret = (long long) ret * cur % mod;
    }
    cur = (long long) cur * cur % mod;
    y >>= 1;
  }
  return ret;
}

long long inv(long long x) {
  return quickPow(x, mod - 2);
}

/*****************************/

long long inv(int x) {
  long long s = 1;
  for (; x > 1; x = mod % x)
    s = s * (mod - mod / x) % mod;
  return s;
}
