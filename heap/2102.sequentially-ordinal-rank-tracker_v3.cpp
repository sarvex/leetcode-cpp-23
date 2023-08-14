#include <algorithm>
#include <queue>
#include <string>
#include <utility>

class SORTracker {
  std::priority_queue<std::pair<int, std::string>> pq1;
  std::priority_queue<std::pair<int, std::string>, vector<std::pair<int, std::string>>, greater<>> pq2;
  std::pair<int, std::string> cur;

public:
  SORTracker() {
    pq1.push({std::numeric_limits<int>::min(), "#"});
  }

  void add(std::string name, int score) {
    std::pair<int, std::string> temp = make_pair(-score, name);
    if (temp > pq1.top())
      pq2.push(temp);
    else {
      pq2.push(pq1.top());
      pq1.pop();
      pq1.push(temp);
    }
  }

  std::string get() {
    auto temp = pq2.top();
    pq1.push(temp);
    pq2.pop();
    return temp.second;
  }
};

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */
