class Solution {
    void dfs(int v, int p, unordered_map<int, vector<int>>& adj, vector<int>& ans) {
        ans.push_back(v);
        for (auto nbr : adj[v])
            if (nbr != p)
                dfs(nbr, v, adj, ans);
    }

public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> adj;
        for (auto& ap : adjacentPairs) {
            adj[ap[0]].push_back(ap[1]);
            adj[ap[1]].push_back(ap[0]);
        }

        int s = INT_MIN;
        for (auto& [v, nbrs] : adj)
            if (nbrs.size() == 1) {
                s = v;
                break;
            }

        vector<int> ans;
        dfs(s, s, adj, ans);

        return ans;      
    }
};

auto _ = [](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
