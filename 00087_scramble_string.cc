class Solution {
    bool isScramble(const string& s1, const string& s2, int i, int j, int len,
                    vector<vector<vector<int>>>& memo) {
        if (memo[len][i][j] != -1)
            return (memo[len][i][j] != 0);
        
        if (len == 1)
            return memo[len][i][j] = (s1[i] == s2[j]);

        for (int k = 1; k < len; ++k)
            if ((isScramble(s1, s2, i, j, k, memo) && isScramble(s1, s2, i + k, j + k, len - k , memo)) ||
                (isScramble(s1, s2, i, j + len - k, k, memo) && isScramble(s1, s2, i + k, j, len - k, memo)))
                    return memo[len][i][j] = 1;

        return memo[len][i][j] = 0;
    }

public:
    bool isScramble(string s1, string s2) {
        if (s1 == s2) return true;

        int n = s1.size();
        vector<vector<vector<int>>> memo(n + 1, vector<vector<int>>(n, vector<int>(n, -1)));
        return isScramble(s1, s2, 0, 0, n, memo);
    }
};

class Solution_DP {
public:
    bool isScramble(string s1, string s2) {
        if (s1 == s2) return true;

        int n = s1.size();
        vector<vector<vector<bool>>> dp(n + 1, vector<vector<bool>>(n, vector<bool>(n)));

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                dp[1][i][j] = (s1[i] == s2[j]);

        for (int len = 2; len <= n; ++len)
            for (int i = 0; i < n - len + 1; ++i)
                for (int j = 0; j < n - len + 1; ++j)
                    for (int k = 1; k < len; ++k)
                        if ((dp[k][i][j] && dp[len - k][i + k][j + k]) ||
                            (dp[k][i][j + len - k] && dp[len - k][i + k][j])) {
                                dp[len][i][j] = true;
                                break;
                            }

        return dp[n][0][0];
        
    }
};
