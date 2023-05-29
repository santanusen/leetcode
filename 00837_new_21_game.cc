class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if (n >= k + maxPts || k == 0) return 1.0;
        double dp[n + 1];
        dp[0] = 1.0;

        double s = 1.0, ans = 0.0;
        for (int i = 1; i <= n; ++i) {
            dp[i] = s / maxPts;
            if (i < k)
                s += dp[i];
            else
                ans += dp[i];

            if (i - maxPts >= 0) s -= dp[i - maxPts]; // slide
        }
        return ans;
    }

    double new21Game_tle(int n, int k, int maxPts) {
        double dp[n + 1];
        dp[0] = 1.0;

        for (int i = 1; i <= n; ++i) {
            dp[i] = 0.0;
            for (int j = 1; j <= maxPts; ++j) {
                if (i - j > -1 && i - j < k)
                    dp[i] += (dp[i - j] / maxPts);
            }
        }

        return accumulate(dp + k, dp + n + 1, 0.0);
        
    }
};
