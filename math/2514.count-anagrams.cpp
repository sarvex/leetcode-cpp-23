#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
  const static long long M = 1e9 + 7;
  long long inv[100005];

public:
  int countAnagrams(std::string s) {
    std::vector<std::string> str_arr;
    std::istringstream in(s);
    int k = 0;
    for (std::string word; in >> word; k++)
      str_arr.push_back(word);

    inv[1] = 1;
    for (int i = 2; i <= 100000; ++i)
      inv[i] = (M - M / i) * inv[M % i] % M;

    long long ret = 1;
    for (auto &str: str_arr) {
      ret = ret * helper(str) % M;
    }
    return ret;
  }

  long long helper(std::string &s) {
    std::unordered_map<int, int> Map;
    for (auto ch: s)
      Map[ch] += 1;

    int N = s.size();
    long long ret = 1;
    for (int i = 1; i <= N; i++)
      ret = ret * i % M;

    for (auto [k, v]: Map) {
      for (int i = 1; i <= v; i++)
        ret = ret * inv[i] % M;
    }
    return ret;
  }
};
