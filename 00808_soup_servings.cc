const int da[] = {4, 3, 2, 1};
const int db[] = {0, 1, 2, 3};

class Solution {
    double dfs(int a, int b, vector<vector<double>>& memo) {
        if (a <= 0) {
            if (b <= 0)
                return 0.5;
            else
                return 1.0;
        }

        if (b <= 0)
            return 0;

        if (memo[a][b] > -1.0)
            return memo[a][b];

        double ans = 0.0;

        for (int d = 0; d < 4; ++d)
            ans += 0.25 * dfs(a - da[d], b - db[d], memo);

        return memo[a][b] = ans;
    }

public:
    double soupServings(int n) {
        if (n > 4800) return 1.0;
        n = (n + 24) / 25;
        //vector dp = vector(n + 1, vector<double>(n + 1, 0));
        double dp[193][193] = {{0}};

        auto calc = [&](int i, int j) -> double {
            return (dp[max(i - 4, 0)][j] +
                    dp[max(i - 3, 0)][j - 1] +
                    dp[max(i - 2, 0)][max(j - 2, 0)] +
                    dp[i - 1][max(j - 3, 0)]) / 4.0;
        };
        
        dp[0][0] = 0.5;
        for (int k = 1; k <= n; ++k) {
            dp[0][k] = 1.0;
            dp[k][0] = 0;

            for (int j = 1; j <= k; ++j) {
                dp[j][k] = calc(j, k);
                dp[k][j] = calc(k, j);
            }
        }

        return dp[n][n];
        
    }

    double soupServings_dfs(int n) {
        if (n > 4800) return 1.0;
        n = (n + 24) / 25;
        vector memo = vector(n + 1, vector<double>(n + 1, -1.0));
        return dfs(n, n, memo);    
    }
};
