#include <algorithm>
#include <string>
#include <vector>

class Solution {
public:
  int characterReplacement(std::string s, int k) {
    std::vector<int> count(26, 0);

    int i = 0;
    size_t result = 0;

    for (size_t j = 0; j < s.size(); j++) {
      count[s[j] - 'A']++;

      while (j - i + 1 - *max_element(count.begin(), count.end()) > k) {
        count[s[i] - 'A']--;
        i++;
      }
      result = std::max(result, j - i + 1);
    }
    return result;
  }
};
