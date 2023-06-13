class Solution {
    int dfs(vector<vector<int>>& adj, int cur, vector<int>& visited, int id) {
        /*
        int l = 1;
        visited[cur] = id;

        for (auto nbr : adj[cur]) {
            if (visited[nbr] != id)
                l += dfs(adj, nbr, visited, id);
        }

        return l;
        */

        int l = 0;
        stack<int> stk;
        stk.push(cur);
        while (!stk.empty()) {
            auto node = stk.top(); stk.pop();
            if (visited[node] == id) continue;
            visited[node] = id;
            ++l;

            for (auto nbr : adj[node])
                if (visited[nbr] != id)
                    stk.push(nbr);
        }

        return l;
    }


public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> adj(n, vector<int>());
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                long long ri = bombs[i][2], rj = bombs[j][2];
                long long dx = bombs[i][0] - bombs[j][0];
                long long dy = bombs[i][1] - bombs[j][1];
                long long d = dx * dx + dy * dy;
                if (d <= ri * ri)
                    adj[i].push_back(j);
                if (d <= rj * rj)
                    adj[j].push_back(i);
            }
        }

        
        int ans = 0;
        vector<int> visited(n, 0);

        for (int i = 0; i < n; ++i)
            ans = max(ans, dfs(adj, i, visited, i + 1));

        return ans;
    }
};
