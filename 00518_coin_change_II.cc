class Solution {
public:
    int change(int amount, vector<int>& coins) {
        //vector<int> dp(amount + 1);
        int dp[5001] = {0};
        dp[0] = 1;

        for (auto c : coins) {
            int imax = amount - c + 1;
            for (int i = 0; i < imax; ++i)
                dp[i + c] += dp[i];
        }

        return dp[amount];
    }
};

auto _ = [](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
