#include <algorithm>
#include <string>
#include <vector>

class Solution {
public:
  int lengthOfLongestSubstring(std::string s) {
    std::vector<int> Map(256, 0);
    int i = 0;
    int j = 0;
    int result = 0;

    while (j < s.size()) {
      if (Map[s[j]] == 0) {
        Map[s[j]] = 1;
        j++;
      } else if (Map[s[j]] == 1) {
        Map[s[i]] = 0;
        i++;
      }

      result = std::max(result, j - i);
    }

    return result;
  }
};
