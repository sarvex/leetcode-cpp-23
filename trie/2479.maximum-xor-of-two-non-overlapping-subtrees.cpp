#include <algorithm>
#include <vector>

class Solution {
  std::vector<int> next[50005];
  long long val[50005];
  std::vector<int> values;

  class TrieNode {
  public:
    TrieNode *next[2];
    TrieNode() {
      for (int i = 0; i < 2; i++)
        next[i] = NULL;
    }
  };
  TrieNode *root;

  long long ret = 0;

public:
  void insert(long long num) {
    TrieNode *node = root;
    for (int i = 63; i >= 0; i--) {
      int d = ((num >> i) & 1);
      if (node->next[d] == NULL)
        node->next[d] = new TrieNode();
      node = node->next[d];
    }
  }

  long long find(long long num) {
    TrieNode *node = root;
    if (root->next[0] == NULL && root->next[1] == NULL) return 0;
    long long ret = 0;
    for (int i = 63; i >= 0; i--) {
      int d = ((num >> i) & 1);
      if (node->next[1 - d] != NULL) {
        ret += (1LL << i);
        node = node->next[1 - d];
      } else {
        ret += 0;
        node = node->next[d];
      }
    }
    return ret;
  }

  long long maxXor(int n, std::vector<std::vector<int>> &edges, std::vector<int> &values) {
    this->values = values;
    for (auto &edge: edges) {
      int a = edge[0], b = edge[1];
      next[a].push_back(b);
      next[b].push_back(a);
    }

    root = new TrieNode();

    dfs(0, -1);

    dfs2(0, -1);

    return ret;
  }

  long long dfs(int cur, int parent) {
    long long v = values[cur];
    for (int nxt: next[cur]) {
      if (nxt == parent) continue;
      v = v + dfs(nxt, cur);
    }
    val[cur] = v;
    return v;
  }

  void dfs2(int cur, int parent) {
    for (int nxt: next[cur]) {
      if (nxt == parent) continue;
      ret = std::max(ret, find(val[nxt]));
      dfs2(nxt, cur);
      insert(val[nxt]);
    }
  }
};
