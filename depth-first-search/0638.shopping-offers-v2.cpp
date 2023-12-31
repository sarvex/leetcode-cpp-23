#include <vector>

class Solution {
  int memo[1 << 18];
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

    int state = 0;
    for (int i = 0; i < N; i++)
      state += needs[i] << (i * 3);

    return dfs(state, price, specials);
  }

  int dfs(int state, std::vector<int> &price, std::vector<std::vector<int>> &specials) {
    if (memo[state] != 0) return memo[state];

    int ret = 0;
    for (int i = 0; i < N; i++)
      ret += (state >> (i * 3)) % 8 * price[i];

    for (auto comb: specials) {
      int flag = 1;
      for (int i = 0; i < N; i++) {
        if ((state >> (i * 3)) % 8 < comb[i]) {
          flag = 0;
          break;
        }
      }
      if (flag == 0) continue;

      int state2 = state;
      for (int i = 0; i < N; i++)
        state2 -= comb[i] * (1 << (i * 3));
      ret = std::min(ret, comb[N] + dfs(state2, price, specials));
    }

    memo[state] = ret;
    return ret;
  }
};
