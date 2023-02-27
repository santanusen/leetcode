class Solution {
    long long choose(long long n, long long k) {
        if (k == 0) return 1;
        return (n * choose(n - 1, k - 1)) / k;
    }
public:
    int uniquePaths(int m, int n) {
        return choose(m + n - 2, n - 1);
    }

    int uniquePaths_dp(int m, int n) {
        int dp[m][n];
        for (int i = 0; i < m; ++i)
            dp[i][0] = 1;

        for (int j = 0; j < n; ++j)
            dp[0][j] = 1;

        for (int i = 1; i < m; ++i)
            for (int j = 1; j < n; ++j)
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];

        return dp[m - 1][n - 1];
    }
};
