class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector dp = vector(2, vector(m, vector<int>(n, INT_MIN)));
        dp[0][0][0] = grid[0][0];

        int dd = 0;

        for (int t = 1; t <= m + n - 2; ++t) {
            //vector dp2 = vector(m, vector<int>(n, INT_MIN));
            /*
            const int ib = max(0, t - (m - 1)), ie = min(m - 1, t);
            const int jb = max(0, t - (n - 1)), je = min(n - 1, t);
            */
            int dc = dd, dn = (dd + 1) % 2;
            dp[dn] = move(vector(m, vector<int>(n, INT_MIN)));
            
            for (int i = 0; i < m && i <= t; ++i) {
                if (t - i >= m) continue;
                for (int j = 0; j < n && j <= t; ++j) {
                    if (t - j >= n) continue;
                    if (grid[i][t - i] == -1 || grid[j][t - j] == -1) continue;

                    /*
                    int val = grid[i][t - i];
                    if (i != j) val += grid[j][t - j];
                    for (int pi = i - 1; pi <= i; ++pi)
                        for (int pj = j - i; pj <= j; ++pj)
                            if (pi >= 0 && pj >= 0)
                                dp2[i][j] = max(dp2[i][j], dp[pi][pj] + val);
                    */

                    int val = dp[dc][i][j];
                    if (i > 0) val = max(val, dp[dc][i - 1][j]);
                    if (j > 0) val = max(val, dp[dc][i][j - 1]);
                    if (i > 0 && j > 0) val = max(val, dp[dc][i - 1][j - 1]);

                    if (val < 0) continue;
                    val += grid[i][t - i];
                    if (i != j) val += grid[j][t - j];

                    dp[dn][i][j] = val;
                }
            }

            dd = (dd + 1) % 2;
        }

        return max(0, dp[dd][m - 1][n - 1]);
    }
};
