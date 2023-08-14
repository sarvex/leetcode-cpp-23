#include <algorithm>
#include <string>
#include <unordered_map>

class Solution {
public:
  int lengthOfLongestSubstring(std::string s) {
    std::unordered_map<int, int> Map;
    int i = 0;
    size_t result = 0;
    for (size_t j = 0; j < s.size(); j++) {
      if (Map.find(s[j]) != Map.end())
        i = std::max(i, Map[s[j]] + 1);
      Map[s[j]] = j;
      result = std::max(result, j - i + 1);
    }
    return result;
  }
};
