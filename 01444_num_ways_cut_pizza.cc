class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        int R = pizza.size(), C = pizza[0].size();

        vector apples(R + 1, vector<int>(C + 1));
        vector dp(k, vector(R, vector<int>(C)));
        for (int r = R - 1; r > -1; --r)
            for (int c = C - 1; c > -1; --c) {
                apples[r][c] = ((pizza[r][c] == 'A') ? 1 : 0) +
                    apples[r + 1][c] + apples[r][c + 1] -
                    apples[r + 1][c + 1];

                dp[0][r][c] = (apples[r][c] > 0 ? 1 : 0);
            }

        const int M = 1E9 + 7;
        for (int cutrem = 1; cutrem < k; ++cutrem) {
            for (int r = 0; r < R; ++r) {
                for (int c = 0; c < C; ++c) {
                    for (int nr = r + 1; nr < R; ++nr)
                        if (apples[r][c] - apples[nr][c] > 0)
                            (dp[cutrem][r][c] += dp[cutrem - 1][nr][c]) %= M;

                    for (int nc = c + 1; nc < C; ++nc)
                        if (apples[r][c] - apples[r][nc] > 0)
                            (dp[cutrem][r][c] += dp[cutrem - 1][r][nc]) %= M;
                }
            }
        }

        return dp[k - 1][0][0];
        
    }
};
