class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        if (n < 2) return 0;
        int ALL = (1 << n) - 1;

        queue<pair<int, int>> q; // cur, mask
        vector<vector<bool>> visited (n, vector<bool>(ALL, false));

        for (int i = 0; i < n; ++i) {
            int mask = (1 << i);
            q.push({i, mask});
            visited[i][mask] = true;
        }

        int l = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [cur, mask] = q.front();
                q.pop();
                if (mask == ALL)
                    return l;

                for (auto nbr : graph[cur]) {
                    int nmask = mask | (1 << nbr);
                    if (nmask == ALL)
                        return l + 1;
                    if (!visited[nbr][nmask]) {
                        q.push({nbr, nmask});
                        visited[nbr][nmask] = true;
                    }
                }
            }
            ++l;
        }

        return -1;
        
    }
};

auto _ = [](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
