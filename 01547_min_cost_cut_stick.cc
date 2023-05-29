class Solution {
    int dfs(vector<int>& cuts, int l, int r, vector<vector<int>>& memo) {
        if (l >= r - 1) return 0;
        if (memo[l][r] != -1) return memo[l][r];

        int cost = cuts[r] - cuts[l];
        int cmin = INT_MAX;
        for (int i = l + 1; i < r; ++i) {
            int ccost = dfs(cuts, l, i, memo) + dfs(cuts, i, r, memo);
            cmin = min(cmin, ccost);
        }

        return (memo[l][r] = cost + cmin);

    }
public:
    int minCost(int n, vector<int>& cuts) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int C = cuts.size();

        /*
        vector<vector<int>> memo(C, vector<int>(C, -1));
        return dfs(cuts, 0, C - 1, memo);
        */

        //vector<vector<int>> dp(C, vector<int>(C, 0));
        int dp[C][C];
        for (int i = 0; i < C - 1; ++i) dp[i][i + 1] = 0;
        for (int ncuts = 1; ncuts < C; ++ncuts) {
            int lmax = C - ncuts - 1;
            for (int l = 0; l < lmax; ++l) {
                int r = l + ncuts + 1;
                int cmin = INT_MAX;
                for (int i = l + 1; i < r; ++i)
                    cmin = min(cmin, dp[l][i] + dp[i][r]);
                dp[l][r] = cmin + cuts[r] - cuts[l];
            }
        }

        return dp[0][C - 1];
    }
};
