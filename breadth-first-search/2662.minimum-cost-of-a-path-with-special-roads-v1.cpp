#include <algorithm>
#include <map>
#include <utility>
#include <vector>

class Solution {
  int dp[405][405];

public:
  int minimumCost(std::vector<int> &start, std::vector<int> &target, std::vector<std::vector<int>> &specialRoads) {
    specialRoads.push_back({start[0], start[1], target[0], target[1], std::abs(start[0] - target[0]) + std::abs(start[1] - target[1])});

    std::vector<std::pair<int, int>> point;
    std::map<long long, long long> reverseMap;
    for (int i = 0; i < specialRoads.size(); i++) {
      auto &road = specialRoads[i];
      int x1 = road[0], y1 = road[1], x2 = road[2], y2 = road[3], c = road[4];
      long long point1 = encode(x1, y1), point2 = encode(x2, y2);
      if (reverseMap.find(point1) == reverseMap.end()) {
        point.push_back({x1, y1});
        reverseMap[point1] = point.size() - 1;
      }
      if (reverseMap.find(point2) == reverseMap.end()) {
        point.push_back({x2, y2});
        reverseMap[point2] = point.size() - 1;
      }
    }
    int n = point.size();

    for (int i = 0; i < n; i++)
      dp[i][i] = 0;

    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) {
        auto [x1, y1] = point[i];
        auto [x2, y2] = point[j];
        dp[i][j] = dp[j][i] = std::abs(x1 - x2) + std::abs(y1 - y2);
      }

    for (auto &road: specialRoads) {
      int x1 = road[0], y1 = road[1], x2 = road[2], y2 = road[3], c = road[4];
      int i = reverseMap[encode(x1, y1)], j = reverseMap[encode(x2, y2)];
      dp[i][j] = std::min(dp[i][j], c);
    }

    for (int k = 0; k < n; k++)
      for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
          dp[i][j] = std::min(dp[i][j], dp[i][k] + dp[k][j]);

    int i = reverseMap[encode(start[0], start[1])], j = reverseMap[encode(target[0], target[1])];
    return dp[i][j];
  }

  long long encode(long long x, long long y) { return (x << 32) + y; }
};
