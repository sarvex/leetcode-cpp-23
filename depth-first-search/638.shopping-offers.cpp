#include <string>
#include <unordered_map>
#include <vector>

class Solution {
  std::unordered_map<std::string, int> Map;
  int N;

public:
  int shoppingOffers(std::vector<int> &price, std::vector<std::vector<int>> &special, std::vector<int> &needs) {
    N = price.size();
    std::vector<std::vector<int>> specials;
    for (int i = 0; i < special.size(); i++) {
      int sum = 0;
      for (int j = 0; j < N; j++)
        sum += special[i][j] * price[j];
      if (sum > special[i].back())
        specials.push_back(special[i]);
    }

    std::string key;
    for (int i = 0; i < N; i++)
      key += "0";
    Map[key] = 0;

    return DFS(price, specials, needs);
  }

  std::string getKey(std::vector<int> &needs) {
    std::string key;
    for (int i = 0; i < needs.size(); i++)
      key += std::to_string(needs[i]);
    return key;
  }

  int DFS(std::vector<int> &price, std::vector<std::vector<int>> &specials, std::vector<int> &needs) {
    std::string key = getKey(needs);
    if (Map.find(key) != Map.end())
      return Map[key];

    int result = std::numeric_limits<int>::max();
    int special_used = 0;
    for (int i = 0; i < specials.size(); i++) {
      int flag = 1;
      for (int j = 0; j < N; j++) {
        if (specials[i][j] > needs[j]) {
          flag = 0;
          break;
        }
      }
      if (flag == 1) {
        special_used = 1;
        std::vector<int> needs_temp = needs;
        for (int j = 0; j < N; j++)
          needs_temp[j] = needs[j] - specials[i][j];
        result = std::min(result, specials[i][N] + DFS(price, specials, needs_temp));
      }
    }
    if (special_used == 0) {
      result = 0;
      for (int i = 0; i < N; i++)
        result += price[i] * needs[i];
    }
    Map[key] = result;

    return result;
  }
};
