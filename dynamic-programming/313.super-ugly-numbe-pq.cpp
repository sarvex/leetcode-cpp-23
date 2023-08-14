class Solution {
public:
  int nthSuperUglyNumber(int n, vector<int> &primes) {
    set<long> Set = {1};
    int count = 0;
    long x;
    while (count < n) {
      x = *Set.begin();
      Set.erase(x);
      for (int i = 0; i < primes.size(); i++) {
        if (x * primes[i] < std::numeric_limits<int>::max())
          Set.insert(x * primes[i]);
        else
          break;
      }

      count++;
    }
    return x;
  }
};
