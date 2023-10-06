class Solution {
public:
    int integerBreak(int n) {
        if (n < 4) return n - 1;
        int dp[n + 1];
        for (int i = 0; i < 5; ++i)
            dp[i] = i;

        for (int i = 5; i <= n; ++i) {
            dp[i] = 0;
            for (int j = 2; j < i; ++j)
                dp[i] = max(dp[i], j * dp[i - j]);
        }
        return dp[n];
    }

    int integerBreak2(int n) {
        if (n < 4) return n - 1;
        int ans = 1;
        while (n > 4) {
            n -= 3;
            ans *= 3;
        }

        return (n * ans);
    }
};

auto _ = [](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
