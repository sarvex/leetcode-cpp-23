#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
  int result;

public:
  int findMinStep(std::string board, std::string hand) {
    result = std::numeric_limits<int>::max();
    std::unordered_map<char, int> Hand;
    for (auto x: hand) Hand[x]++;

    DFS(board, Hand, 0);
    if (result == std::numeric_limits<int>::max()) return -1;
    else
      return result;
  }

  void DFS(std::string board, std::unordered_map<char, int> &Map, int curCount) {
    if (board == "") {
      result = std::min(result, curCount);
      return;
    }
    if (curCount >= result) return;

    for (int i = 0; i < board.size(); i++) {
      int i0 = i;
      while (i < board.size() && board[i] == board[i0]) i++;
      if (3 - (i - i0) <= Map[board[i0]]) {
        std::string newBoard = board.substr(0, i0) + board.substr(i);
        newBoard = clean(newBoard);
        Map[board[i0]] -= (3 - (i - i0));
        DFS(newBoard, Map, curCount + (3 - (i - i0)));

        Map[board[i0]] += (3 - (i - i0));
      }
      i--;
    }
  }

  std::string clean(std::string s) {
    std::string t = "";
    while (1) {
      t = "";
      for (int i = 0; i < s.size(); i++) {
        int i0 = i;
        while (i < s.size() && s[i] == s[i0]) i++;
        if (i - i0 < 3)
          t = t + s.substr(i0, i - i0);
        i--;
      }
      if (t == s) return t;
      s = t;
    }
    return s;
  }
};
