class Solution {
    const int MOD = 1E9 + 7;
    int DP[101][101][101];

public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        // Base case
        for(int c = 0; c <= n; ++c)
            DP[group.size()][c][minProfit] = 1;

        for (int i = group.size() - 1; i >= 0; --i) {
            for (int c = 0; c <= n; ++c) {
                for (int p = 0; p <= minProfit; ++p) {
                    DP[i][c][p] = DP[i + 1][c][p];
                    if (c + group[i] <= n) {
                        DP[i][c][p] = (
                            DP[i][c][p] +
                            DP[i + 1][c + group[i]][min(minProfit, p + profit[i])]
                        ) % MOD;
                    }
                }
            }
        }
        return DP[0][0][0];
    }

};

class Solution_memo {
    const int MOD = 1E9 + 7;
    int DP[101][101][101];
    int numSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit, int i, int curProfit /*,
                    vector<vector<vector<int>>>& DP*/) {
        if (n <= 0 || i >= group.size()) return 0;
        if (curProfit >= minProfit) curProfit = minProfit;
        if (DP[i][n][curProfit] != -1) return DP[i][n][curProfit];
        int nschemes = 0;
        
        if (n >= group[i]) {
            if (curProfit + profit[i] >= minProfit) ++nschemes;
            nschemes += numSchemes(n - group[i], minProfit, group, profit, i + 1, curProfit + profit[i]/*, DP*/);
            nschemes %= MOD;
        }

        nschemes += numSchemes(n, minProfit, group, profit, i + 1, curProfit/*, DP*/);
        nschemes %= MOD;
        DP[i][n][curProfit] = nschemes;
        return nschemes;
    }

public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        //vector DP(group.size(), vector(n + 1, vector<int>(minProfit + 1, -1))); // i, n, curprofit
        memset(DP, -1, sizeof(DP));
        return numSchemes(n, minProfit, group, profit, 0, 0/*, DP*/) + (minProfit == 0 ? 1 : 0);
    }
};
