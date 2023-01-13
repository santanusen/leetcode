class Solution {
    int dfs(int cur, int par, vector<vector<int>>& nbrs, vector<bool>& hasApple) {
        int trip = 0;
        for (auto chld : nbrs[cur])
            if (chld != par)
                trip += dfs(chld, cur, nbrs, hasApple);
        // If current node or any of its children has apples,
        // add 2 for roundtrip to this node from its parent.
        // No cost for trip to the root node though, as it does not
        // have a parent.
        if (cur != 0 && (hasApple[cur] || trip)) trip += 2;
        return trip;
    }
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> nbrs(n);
        for (auto& e : edges) {
            nbrs[e[0]].push_back(e[1]);
            nbrs[e[1]].push_back(e[0]);
        }
        return dfs(0, 0, nbrs, hasApple);
    }
};
