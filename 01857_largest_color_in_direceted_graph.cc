class Solution {
    struct Memo {
        int freq[26];
        Memo() : freq {0} {}
    };

    int ans;

    void dfs(int cur, vector<vector<int>>& adj,
             const string& colors,
             unordered_map<int, Memo*>& DP,
             vector<bool>& visited) {
        if (ans == INT_MAX) return;
        if (visited[cur]) {
            ans = INT_MAX;
            return;
        }

        if (DP.find(cur) != DP.end())
            return;

        visited[cur] = true;

        Memo* cmemo = new Memo;
        DP[cur] = cmemo;
        for (auto nbr : adj[cur]) {
            dfs(nbr, adj, colors, DP, visited);
            if (ans == INT_MAX) return;
            auto nmemo = DP[nbr];
            for (int i = 0; i < 26; ++i) {
                cmemo->freq[i] = max(cmemo->freq[i], nmemo->freq[i]);
                ans = max(ans, cmemo->freq[i]);
            }
        }
        ans = max(ans, ++cmemo->freq[colors[cur] - 'a']);
        visited[cur] = false;
    }

public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        vector<vector<int>> adj(colors.size());
        for (auto& e: edges)
            adj[e[0]].push_back(e[1]);

        unordered_map<int, Memo*> DP;
        ans = 0;

        for (int node = 0; node < colors.size(); ++node)
            if (DP.find(node) == DP.end()) {
                vector<bool> visited(colors.size(), false);
                dfs(node, adj, colors, DP, visited);
            }

        return (ans == INT_MAX) ? -1 : ans;
        
    }
};
