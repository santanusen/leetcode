class Solution2 {
    //vector<vector<vector<int>>> memo;
    int memo[51][101][51] = {{{0}}};


    int n;
    int m;
    int MOD = 1e9 + 7;

    int dfs(int i, int mm, int k) {
        if (i == n) {
            if (k == 0)
                return 1;
            return 0;
        }

        if (k < 0)
            return 0;

        if (memo[i][mm][k] != 0)
            return memo[i][mm][k] - 1;

        int ans = 0;
        /*
        for (int num = 0; num < mm; ++num)
            ans = (ans + dfs(i + 1, mm, k)) % MOD;
        */
        ans = (ans + static_cast<uint64_t>(mm) * (dfs(i + 1, mm, k) % MOD)) % MOD;

        for (int num = mm + 1; num <= m; ++num)
            ans = (ans + dfs(i + 1, num, k - 1)) % MOD;

        memo[i][mm][k] = ans + 1;
        return ans;
    }

public:
    int numOfArrays2(int n, int m, int k) {
    #if 0
        this->n = n;
        this->m = m;
        //memo = vector(n, vector(m + 1, vector(k + 1, -1)));
        return dfs(0, 0, k);
    #else
        for (int mm = 0; mm <= m; ++mm)
            memo[n][mm][0] = 1;

        for (int i = n - 1; i > -1; --i) {
            for (int mm = m; mm > -1; --mm) {
                for (int kk = 0; kk <= k; ++kk) {
                    int ans = 0;
                    ans = (ans + static_cast<uint64_t>(mm) * memo[i + 1][mm][kk] % MOD) % MOD;
                    if (kk > 0)
                        for (int num = mm + 1; num <= m; ++num)
                            ans = (ans + memo[i + 1][num][kk - 1]) % MOD;
                    memo[i][mm][kk] = ans;
                }
            }
        }

        return memo[0][0][k];

    #endif
    }
};

class Solution {
public:
    int numOfArrays(int n, int m, int k) {
        if (m < k) return 0;

        int dp[2][m + 1][k + 1], MOD = 1e9 + 7;
        memset(dp, 0, sizeof(dp));
        for (int j = 1; j <= m; ++j)
            dp[0][j][1]=j;

        for (int i = 1; i < n; ++i)
            for (int j = 1; j <= m; ++j)
                for (int l = 1; l <= min({i + 1, j, k}); ++l)
                    dp[i & 1][j][l] = (dp[i & 1][j - 1][l] +
                                      (long)(dp[(i - 1) & 1][j][l] - dp[(i - 1) & 1][j - 1][l]) * j +
                                      dp[(i - 1) & 1][j - 1][l - 1]) % MOD;

        return (dp[(n - 1) & 1][m][k] + MOD) % MOD;
        //return dp[(n - 1) & 1][m][k];
    }
};

auto _ = [](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
