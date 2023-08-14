#include <algorithm>
#include <string>
#include <vector>

class Solution {
public:
  int lengthOfLongestSubstringTwoDistinct(std::string s) {
    std::vector<int> Map(256, 0);
    int count = 0;
    int result = 0;
    int i = 0;
    int j = 0;

    for (int j = 0; j < s.size(); j++) {
      if (Map[s[j]] > 0) {
        Map[s[j]]++;
      } else if (Map[s[j]] == 0 && count < 2) {
        Map[s[j]]++;
        count++;
      } else if (Map[s[j]] == 0 && count == 2) {
        while (count == 2) {
          Map[s[i]]--;
          if (Map[s[i]] == 0)
            count--;
          i++;
        }
        Map[s[j]]++;
        count++;
      }

      result = std::max(result, j - i + 1);
    }

    return result;
  }
};
