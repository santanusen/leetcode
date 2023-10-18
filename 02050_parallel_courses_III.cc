class Solution {
    void dfs(int i, vector<vector<int>>& nxt, vector<int>& time, vector<int>& cost) {
        if (cost[i] != -1)
            return;
        
        int cmax = 0;
        for (auto j : nxt[i]) {
            if (cost[j] == -1)
                dfs(j, nxt, time, cost);
            cmax = max(cmax, cost[j]);
        }

        cost[i] = cmax + time[i];
    }

public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> nxt(n);
        for (auto& r : relations)
            nxt[r[0] - 1].push_back(r[1] - 1);

        vector<int> cost(n, -1);
        int maxcost = -1;

        for (int i = 0; i < n; ++i) {
            if (cost[i] == -1) {
                dfs(i, nxt, time, cost);
            }
            maxcost = max(maxcost, cost[i]);
        }

        return maxcost;
        
    }
};

auto _ = [](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
