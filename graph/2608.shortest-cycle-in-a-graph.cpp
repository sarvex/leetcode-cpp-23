class Solution {
    unordered_set<int>next[1005];
    int n;
public:
    int findShortestCycle(int n, vector<vector<int>>& edges)
    {
        this->n = n;
        for (auto&edge: edges)
        {
            int a = edge[0], b = edge[1];
            next[a].insert(b);
            next[b].insert(a);
        }

        int ret = std::numeric_limits<int>::max();
        for (auto&edge: edges)
        {
            int a = edge[0], b = edge[1];
            next[a].erase(b);
            next[b].erase(a);
            ret = min(ret, BFS(a,b));
            next[a].insert(b);
            next[b].insert(a);
        }

        if (ret==std::numeric_limits<int>::max()) return -1;
        return ret+1;
    }

    int BFS(int start, int end)
    {
        vector<int>visited(n);
        queue<int>q;
        q.push(start);
        visited[start] = 1;

        int step = 0;
        while (!q.empty())
        {
            int len = q.size();
            while (len--)
            {
                int cur = q.front();
                q.pop();
                if (cur==end) return step;
                for (int nxt: next[cur])
                {
                    if (visited[nxt]) continue;
                    q.push(nxt);
                    visited[nxt] = 1;
                }
            }
            step++;
        }
        return std::numeric_limits<int>::max();
    }
};
