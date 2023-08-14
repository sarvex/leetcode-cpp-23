#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
  std::vector<int> findSubstring(std::string s, std::vector<std::string> &words) {
    int N = words[0].size();
    int COUNT = words.size();
    std::unordered_map<std::string, int> Table;
    for (int i = 0; i < words.size(); i++)
      Table[words[i]]++;

    std::vector<int> results;
    for (int start = 0; start < N; start++) {
      int i = start;
      int j = i;
      int count = 0;
      std::unordered_map<std::string, int> Map;

      while (j < s.size()) {
        if (Table.find(s.substr(j, N)) == Table.end()) {
          Map.clear();
          count = 0;
          j += N;
          i = j;
        } else if (Map[s.substr(j, N)] < Table[s.substr(j, N)]) {
          Map[s.substr(j, N)]++;
          count++;
          j += N;
        } else if (Map[s.substr(j, N)] == Table[s.substr(j, N)]) {
          Map[s.substr(i, N)]--;
          i += N;
          count--;
        }

        if (count == COUNT) {
          results.push_back(i);
          Map[s.substr(i, N)]--;
          i += N;
          count--;
        }
      }
    }

    return results;
  }
};
