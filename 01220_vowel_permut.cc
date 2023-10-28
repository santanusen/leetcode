class Solution {
    enum {a = 0, e = 1, i = 2, o = 3, u = 4, NV = 5};
public:
    int countVowelPermutation(int n) {
        const int MOD = 1e9 + 7;
        long dp[2][NV] = {{0, 0, 0, 0, 0}, {1, 1, 1, 1, 1}};

        for (int x = 1; x < n; ++x) {
            int cur = (x & 0x1);
            int nxt = (~x & 0x1);

            dp[nxt][a] = dp[cur][e];
            dp[nxt][e] = (dp[cur][a] + dp[cur][i]) % MOD;
            dp[nxt][i] = (dp[cur][a] + dp[cur][e] + dp[cur][o] + dp[cur][u]) % MOD;
            dp[nxt][o] = (dp[cur][i] + dp[cur][u]) % MOD;
            dp[nxt][u] = dp[cur][a];
        }

        int cur = n & 0x1;
        return (dp[cur][a] + dp[cur][e] + dp[cur][i] + dp[cur][o] + dp[cur][u]) % MOD;
        
    }
};

auto _ = [](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
