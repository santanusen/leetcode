class Solution {
    bool dfs(vector<vector<int>>& adj, int cur, vector<bool>& vst, vector<bool>& stk) {
        if (stk[cur]) return true; // Cycle
        if (vst[cur]) return false;

        vst[cur] = true;
        stk[cur] = true;

        for (auto nbr : adj[cur])
            if (dfs(adj, nbr, vst, stk))
                return true;

        stk[cur] = false;
        return false;
    }

public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);
        for (auto e : prerequisites)
            adj[e[0]].push_back(e[1]);

        vector<bool> vst(n), stk(n);
        for(int i = 0; i < n; ++i)
            if (dfs(adj, i, vst, stk))
                return false;

        return true;
        
    }
};

auto _ = [](){ios::sync_with_stdio(false); cin.tie(0); cout.tie(0); return false;}();
