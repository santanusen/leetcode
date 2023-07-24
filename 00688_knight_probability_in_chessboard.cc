int dx[] = {+2, +2, -2, -2, +1, +1, -1, -1};
int dy[] = {+1, -1, +1, -1, +2, -2, +2, -2};

class Solution {

    double dfs (int n, int k, int r, int c, vector<vector<vector<double>>>& memo) {

        if (r < 0 || r >= n || c < 0 || c >= n)
            return 0.0;

        if (k == 0)
            return 1.0;

        if (memo[k - 1][r][c] > -1.0)
            return memo[k - 1][r][c];

        double ans = 0.0;
        for (int d =0; d < 8; ++d) {
            ans +=
            (dfs(n, k - 1, r + dx[d], c + dy[d], memo) / 8.0);
        }

        return memo[k - 1][r][c] = ans;

    }

public:
    double knightProbability(int n, int k, int row, int column) {
        //vector dp(k + 1, vector(n, vector<double>(n)));
        double dp[2][n][n];
        for (int r = 0; r < n; ++r)
            for (int c = 0; c < n; ++c)
                dp[0][r][c] = 0;

        dp[0][row][column] = 1.0;

        for (int m = 1; m <= k; ++m) {
            int dcur = m % 2, dprv = (m + 1) % 2;
            for (int r = 0; r < n; ++r)
                for (int c = 0; c < n; ++c) {
                    dp[dcur][r][c] = 0;
                    for (int d = 0; d < 8; ++d) {
                        int x = r - dx[d], y = c - dy[d];
                        if (x > -1 && x < n && y > -1 && y < n)
                            dp[dcur][r][c] += (dp[dprv][x][y] / 8.0);
                    }
                }
        }

        double ans = 0;
        for (auto &dpr : dp[k % 2])
            for (auto p : dpr)
                ans += p;
        return ans;
    }

    double knightProbability_dp2(int n, int k, int row, int column) {
        vector dp(k + 1, vector(n, vector<double>(n)));
        for (int r = 0; r < n; ++r)
            for (int c = 0; c < n; ++c)        
                dp[0][r][c] = 1.0;

        for (int m = 1; m <= k; ++m)
            for (int r = 0; r < n; ++r)
                for (int c = 0; c < n; ++c)
                    for (int d = 0; d < 8; ++d) {
                        int x = r + dx[d], y = c + dy[d];
                        if (x > -1 && x < n && y > -1 && y < n)
                            dp[m][r][c] += (dp[m - 1][x][y] / 8.0);
                    }

        return dp[k][row][column];
    }

    double knightProbability_rec(int n, int k, int row, int column) {
        vector<vector<vector<double>>> memo(k, vector<vector<double>>(n, vector<double>(n, -2.0)));
        return dfs(n, k, row, column, memo);
    }
};

auto _ = [](){ios::sync_with_stdio(false); cin.tie(0); cout.tie(0); return 0;}();
