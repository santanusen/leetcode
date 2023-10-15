class Solution {
    const int MOD = 1E9 + 7;
    int dfs(int pos, int rem_steps, int arrLen, vector<vector<int>>& dp) {
        if (rem_steps == 0) {
            if (pos == 0)
                return 1;
            else
                return 0;
        }



        if (pos > rem_steps) // Not enough steps to reach back to 0
            return /*dp[pos][rem_steps - 1] =*/ 0;

        if (pos == rem_steps)
            return /*dp[pos][rem_steps - 1] =*/ 1;

        if (dp[pos][rem_steps - 1] != -1)
            return dp[pos][rem_steps - 1];

        int ans = 0;
        static int dd[] = {-1, 0, 1};
        for (auto d : dd) {
            int pnxt = pos + d;
            if (pnxt > -1 && pnxt < arrLen)
                ans = (ans + dfs(pnxt, rem_steps - 1, arrLen, dp)) % MOD;
        }

        return dp[pos][rem_steps - 1] = ans;
    }

public:
    int numWays_dfs(int steps, int arrLen) {
        vector<vector<int>> dp(steps, vector<int>(steps, -1));
        return dfs(0, steps, arrLen, dp);    
    }

    int numWays(int steps, int arrLen) {
        arrLen = min(arrLen, steps);
        vector<vector<int>> dp(arrLen, vector(steps + 1, 0));
        dp[0][0] = 1;
        
        for (int remain = 1; remain <= steps; remain++) {
            for (int curr = arrLen - 1; curr >= 0; curr--) {
                int ans = dp[curr][remain - 1];
                
                if (curr > 0) {
                    ans = (ans + dp[curr - 1][remain - 1]) % MOD;
                }
                
                if (curr < arrLen - 1) {
                    ans = (ans + dp[curr + 1][remain - 1]) % MOD;
                }
                
                dp[curr][remain] = ans;
            }
        }
        
        return dp[0][steps];
    }
};

auto _ = [](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
