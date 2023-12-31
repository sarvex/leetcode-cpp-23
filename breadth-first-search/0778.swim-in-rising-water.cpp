#include <algorithm>
#include <queue>
#include <vector>
class Solution
{
public:
  int swimInWater(std::vector<std::vector<int>> &grid)
  {
    std::priority_queue < std::vector<int>, std::vector<std::vector<int>, greater<std::vector<int>>> pq;
    pq.push({grid[0][0], 0, 0});

    int N = grid.size();
    auto visited = std::vector<std::vector<int>>(N, std::vector<int>(N, 0));

    int ret = 0;
    auto dir = std::vector<pair<int, int>>({{1, 0}, {-1, 0}, {0, 1}, {0, -1}});

    while (!pq.empty())
    {
      int h = pq.top()[0];
      int x = pq.top()[1];
      int y = pq.top()[2];
      ret = max(ret, h);
      pq.pop();

      if (visited[x][y])
        continue;
      visited[x][y] = 1;

      if (x == N - 1 && y == N - 1)
        return ret;

      for (int k = 0; k < 4; k++)
      {
        int xx = x + dir[k].first;
        int yy = y + dir[k].second;
        if (xx < 0 || xx >= N || yy < 0 || yy >= N)
          continue;
        if (visited[xx][yy] == 1)
          continue;
        pq.push({grid[xx][yy], xx, yy});
      }
    }

    return -1;
  }
};
