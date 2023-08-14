#include <algorithm>
#include <map>
#include <string>
#include <utility>

class Solution {
  std::map<std::pair<long long, long long>, int> Map;

public:
  long long fixedRatio(std::string s, int num1, int num2) {
    Map[{0, 0}] = 1;
    long long a = 0, b = 0;
    long long ret = 0;
    for (auto ch: s) {
      if (ch == '0') a++;
      else
        b++;

      long long k = std::min(a / num1, b / num2);
      long long x = a - k * num1, y = b - k * num2;

      if (Map.find({x, y}) != Map.end())
        ret += Map[{x, y}];

      Map[{x, y}] += 1;
    }

    return ret;
  }
};
