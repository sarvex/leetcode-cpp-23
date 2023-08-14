#include <ext/pb_ds/assoc_container.hpp>// Common file
#include <ext/pb_ds/tree_policy.hpp>    // Including tree_order_statistics_node_update
using namespace __gnu_pbds;

#include <set>
#include <unordered_set>
#include <vector>

typedef std::pair<int, int> PII;

typedef tree<
  std::pair<int, int>,
  null_type,
  less<std::pair<int, int>>,
  rb_tree_tag,
  tree_order_statistics_node_update>
  std::ordered_set;


class Solution {
public:
  int createSortedArray(std::vector<int> &instructions) {
    std::ordered_set Set;
    std::unordered_map<int, int> count;
    long cost = 0;
    long M = 1e9 + 7;
    for (auto x: instructions) {
      int k1 = Set.order_of_key({x, 1});
      int k2 = Set.size() - k1 - count[x];
      cost += min(k1, k2);
      cost %= M;
      count[x]++;
      Set.insert({x, count[x]});
    }
    return cost;
  }
};
