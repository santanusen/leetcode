class Solution {
    void dfs(int cur, vector<vector<int>>& nbrs, const string& labels,
             vector<int>& freq, vector<int>& res) {
        int pcount = freq[labels[cur] - 'a']++; // Remember count passed down from parent.
        res[cur] = 1; // Mark visited.
        for (auto chld : nbrs[cur])
            if (!res[chld])
                dfs(chld, nbrs, labels, freq, res);

        // Count only the contributions from current node and its children,
        // leaving out what was passed down from the parent.
        res[cur] = freq[labels[cur] - 'a'] - pcount;
    }

public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> nbrs(n);
        for (auto& e : edges) {
            nbrs[e[0]].push_back(e[1]);
            nbrs[e[1]].push_back(e[0]);
        }

        vector<int> freq(26, 0), res(n);
        dfs(0, nbrs, labels, freq, res);
        return res;
    }
};
