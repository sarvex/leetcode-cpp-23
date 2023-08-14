#include <unordered_set>
#include <vector>

class Solution {
  const static long long M = 1e9 + 7;

public:
  int equalDigitFrequency(string s) {
    std::vector<int> count(10);
    std::unordered_set<long long> Set;

    int n = s.size();
    for (int i = 0; i < n; i++) {
      count.assign(10, -1);
      long long hash = 0;

      for (int j = i; j < n; j++) {
        hash = hash * 11 + (s[j] - '0' + 1);
        hash = hash % M;

        count[s[j] - '0']++;

        int freq = -1;
        int flag = 1;
        for (int k = 0; k < 10; k++) {
          if (count[k] == -1) continue;
          if (freq == -1)
            freq = count[k];
          else if (freq != count[k]) {
            flag = 0;
            break;
          }
        }
        if (flag) Set.insert(hash);
      }
    }

    return Set.size();
  }
};
