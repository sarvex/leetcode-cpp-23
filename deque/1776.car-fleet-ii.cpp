#include <array>
#include <deque>
#include <vector>

class Solution {
public:
  std::vector<double> getCollisionTimes(std::vector<std::vector<int>> &cars) {
    int n = cars.size();
    std::vector<double> rets(n);

    std::deque<std::array<double, 2>> dq;// {t, v}
    dq.push_back({0, (double) cars.back()[1]});
    rets[n - 1] = -1;


    for (int i = cars.size() - 2; i >= 0; i--) {
      int dS = cars[i + 1][0] - cars[i][0];
      double vv = cars[i][1];
      double total = 0;

      if (vv <= dq.back()[1]) {
        dq.clear();
        dq.push_back({0, vv});
        rets[i] = -1;
        continue;
      }

      double t = dq.front()[0];
      double v = dq.front()[1];
      dq.pop_front();

      while (dq.size() > 0) {
        if (total + v * (dq.front()[0] - t) + dS >= vv * dq.front()[0]) {
          total += v * (dq.front()[0] - t);
          t = dq.front()[0];
          v = dq.front()[1];
          dq.pop_front();
        } else
          break;
      }

      double dt = (dS - (t * vv - total)) * 1.0 / (vv - v);

      dq.push_front({t + dt, v});
      dq.push_front({0, vv});

      rets[i] = t + dt;
    }

    return rets;
  }
};
