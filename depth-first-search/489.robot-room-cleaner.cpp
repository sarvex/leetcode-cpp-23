#include <string>
#include <unordered_set>
#include <utility>
#include <vector>

// This is the robot's control interface.
// You should not implement it, or speculate about its implementation
class Robot {
public:
  // Returns true if the cell in front is open and robot moves into the cell.
  // Returns false if the cell in front is blocked and robot stays in the current cell.
  bool move();

  // Robot will stay in the same cell after calling turnLeft/turnRight.
  // Each turn will be 90 degrees.
  void turnLeft();
  void turnRight();

  // Clean the current cell.
  void clean();
};

class Solution {
  std::unordered_set<std::string> visited;
  int dir;

public:
  void cleanRoom(Robot &robot) {
    std::string code = std::to_string(0) + "#" + std::to_string(0);
    visited.insert(code);
    DFS(robot, 0, 0, 0);//[x,y,dir]
  }

  void DFS(Robot &robot, int x, int y, int curDir) {
    std::vector<std::pair<int, int>> dir({{0, 1}, {1, 0}, {0, -1}, {-1, 0}});
    robot.clean();
    for (int k = 1; k <= 4; k++) {
      robot.turnRight();
      int nxtDir = (curDir + k) % 4;
      int i = x + dir[nxtDir].first;
      int j = y + dir[nxtDir].second;
      std::string code = std::to_string(i) + "#" + std::to_string(j);

      if (visited.find(code) == visited.end() && robot.move()) {
        visited.insert(code);
        DFS(robot, i, j, nxtDir);
        robot.turnLeft();
        robot.turnLeft();
        robot.move();
        robot.turnLeft();
        robot.turnLeft();
      }
    }
  }
};
