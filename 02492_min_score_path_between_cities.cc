class Solution {

    int findParent(int x, vector<int>& par) {
        if (par[x] != x)
            par[x] = findParent(par[x], par);
        return par[x];
    }

    void djsUnion(int a, int b, vector<int>& par) {
        int pa = findParent(a, par);
        int pb = findParent(b, par);
        if (pa != pb)
            par[pb] = pa;
    }

public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<int> par(n + 1);
        for (int i = 0; i < n + 1; ++i) par[i] = i;

        for (auto& r : roads)
            djsUnion(r[0], r[1], par);

        int ans = INT_MAX;
        for (auto& r : roads)
            if (r[0] == 1 || r[0] == n || r[1] == 1 || r[1] == n ||
                findParent(1, par) == findParent(r[0], par))
                ans = min(ans, r[2]);

        return ans;
    }

};

class Solution2 {
    int dfs(vector<vector<pair<int, int>>>& nbrs, int cur, vector<bool>& visited) {        
        int min_sc = INT_MAX;
        for (auto [nbr, score] : nbrs[cur]) {
            min_sc = min(min_sc, score);
            if (!visited[nbr]) {
                visited[nbr] = true;
                min_sc = min(min_sc, dfs(nbrs, nbr, visited));
            }
        }
        return min_sc;
    }

public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> nbrs(n);
        for (auto& r : roads) {
            nbrs[r[0] - 1].push_back({r[1] - 1, r[2]});
            nbrs[r[1] - 1].push_back({r[0] - 1, r[2]});
        }

        vector<bool> visited(n, false);
        visited[0] = true;
        return dfs(nbrs, 0, visited);
    }
};
