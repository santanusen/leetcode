static const int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        int dp[n][n + 1];
        memset(dp, 0, sizeof(dp));

        int suffix = 0;
        for (int i = n - 1; i > -1; --i) {
            suffix += piles[i];
            int mmax = i / 2 + 1;
            for (int m = 1; m <= mmax; ++m) {
                if (i + m * 2 >= n) {
                    dp[i][m] = suffix;
                } else {
                    int minB = INT_MAX;
                    for (int x = 1; x <= 2 * m; ++x)
                        minB = min(minB, dp[i + x][max(x, m)]);
                    dp[i][m] = suffix - minB;
                }
            }
        }
        return dp[0][1];
    }
};

class Solution3 {
    int dfs(int i, int M, vector<int>& sufsum, vector<vector<int>>& dp) {
        if (i + 2 * M >= dp.size()) return sufsum[i];
        if (dp[i][M]) return dp[i][M];

        int opp = sufsum[i];
        for (int x = 1; x <= 2 * M; ++x)
            opp = min(opp, dfs(i + x, max(M, x), sufsum, dp));
        return dp[i][M] = sufsum[i] - opp;
    }

public:
    int stoneGameII(vector<int>& piles) {
        const int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        // Suffix sum
        for (int i = n - 2; i > -1; --i)
            piles[i] += piles[i + 1];
        return dfs(0, 1, piles, dp);
    }
};

class Solution1 {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector dp(2, vector(n + 1, vector<int>(n + 1, -1)));

        function<int(int, int, int)> f = [&](int p, int i, int m) -> int {
            if (i == n) return 0;
            if (dp[p][i][m] != -1) return dp[p][i][m];

            int res = (p == 1 ? INT_MAX : INT_MIN);
            int psum = 0, xmax = min(2 * m, n - i);

            for (int x = 1; x <= xmax; ++x) {
                psum += piles[i + x - 1];
                if (p == 0)
                    res = max(res, psum + f(1, i + x, max(m, x)));
                else
                    res = min(res, f(0, i + x, max(m, x)));
            }

            return dp[p][i][m] = res;
        };

        return f(0, 0, 1);
    }
};

class Solution2 {
    pair<int, int> dfs(vector<int>& piles, int turn, int pos, int M, vector<vector<pair<int, int>>>& memo) {
        if (pos >= piles.size()) return {0, 0};
        int midx = M - 1;
        if (memo[pos][midx].first != -1) {
            return (turn == 0 ? memo[pos][midx] : make_pair(memo[pos][midx].second, memo[pos][midx].first));
        }
        int nturn = (turn + 1) % 2;

        int vmax = INT_MIN, oth = 0;

        int psum = 0;
        int XMAX = min(2 * M, int(piles.size()) - pos);
        for (int X = 1; X <= XMAX; ++X) {
            psum += piles[pos + X - 1];
            auto [A, B] = dfs(piles, nturn, pos + X, max(M, X), memo);
            int val = psum + (turn == 0 ? A : B);
            if (val > vmax) {
                vmax = val;
                oth = (turn == 0 ? B : A);
            }
        }
        memo[pos][midx] = make_pair(vmax, oth);

        return (turn == 0 ? make_pair(vmax, oth) : make_pair(oth, vmax));

    }

public:
    int stoneGameII(vector<int>& piles) {
        vector<vector<pair<int, int>>> memo(piles.size(), vector<pair<int, int>>(piles.size(), {-1, -1}));
        return dfs(piles, 0, 0, 1, memo).first;
    }
};
