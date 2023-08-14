#include <utility>
#include <vector>

class Solution
{
  int M, N;
  std::vector<std::pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
  bool hasPath(std::vector<std::vector<int>> &maze, std::vector<int> &start, std::vector<int> &destination)
  {
    if (start == destination)
      return true;

    M = maze.size();
    N = maze[0].size();

    auto visited = std::vector<std::vector<int>>(M, std::vector<int>(N, 0));

    queue<std::pair<int, int>> q;
    q.push({start[0], start[1]});
    visited[start[0]][start[1]] = 1;

    while (!q.empty())
    {
      int x0 = q.front().first;
      int y0 = q.front().second;
      q.pop();

      for (int k = 0; k < 4; k++)
      {
        auto [x, y] = nextPos(maze, x0, y0, k);
        if (x == destination[0] && y == destination[1])
          return true;
        if (visited[x][y] == 1)
          continue;
        visited[x][y] = 1;
        q.push({x, y});
      }
    }
    return false;
  }

  std::pair<int, int> nextPos(std::vector<std::vector<int>> &maze, int x0, int y0, int k)
  {
    int x = x0, y = y0;
    while (x >= 0 && x < M && y >= 0 && y < N && maze[x][y] != 1)
    {
      x += dir[k].first;
      y += dir[k].second;
    }
    x -= dir[k].first;
    y -= dir[k].second;
    return {x, y};
  }
};
