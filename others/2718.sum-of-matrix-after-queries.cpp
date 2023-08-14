#include <vector>

class Solution {
public:
  long long matrixSumQueries(int n, std::vector<std::vector<int>> &queries) {
    std::vector<int> row(n, -1);
    std::vector<int> col(n, -1);
    long long rowLeft = n;
    long long colLeft = n;
    long long ret = 0;
    reverse(queries.begin(), queries.end());
    for (auto &q: queries) {
      int type = q[0], idx = q[1], val = q[2];
      if (type == 0) {
        if (row[idx] != -1) continue;
        row[idx] = val;
        ret += rowLeft * val;
        colLeft--;
      } else {
        if (col[idx] != -1) continue;
        col[idx] = val;
        ret += colLeft * val;
        rowLeft--;
      }
    }
    return ret;
  }
};
