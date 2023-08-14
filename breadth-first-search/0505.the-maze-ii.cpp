#include <queue>
#include <vector>

class Solution
{
public:
  int shortestDistance(std::vector<std::vector<int>> &maze, std::vector<int> &start, std::vector<int> &destination)
  {
    int M = maze.size();
    int N = maze[0].size();

    auto dir = std::vector<pair<int, int>>({{1, 0}, {-1, 0}, {0, 1}, {0, -1}});
    auto resolved = std::vector<std::vector<int>>(M, std::vector<int>(N, 0));

    std::priority_queue<VI, std::vector<VI>, greater<>> pq;
    pq.push({0, start[0], start[1]});

    while (!pq.empty())
    {
      int d = pq.top()[0];
      int x = pq.top()[1];
      int y = pq.top()[2];
      pq.pop();
      if (x == destination[0] && y == destination[1])
        return d;

      if (resolved[x][y] == 1)
        continue;
      resolved[x][y] = 1;

      for (int k = 0; k < 4; k++)
      {
        int i = x, j = y, step = 0;
        while (i + dir[k].first >= 0 && i + dir[k].first < M && j + dir[k].second >= 0 && j + dir[k].second < N && maze[i + dir[k].first][j + dir[k].second] == 0)
        {
          step++;
          i = i + dir[k].first;
          j = j + dir[k].second;
        }
        if (resolved[i][j])
          continue;
        pq.push({d + step, i, j});
      }
    }

    return -1;
  }
};
