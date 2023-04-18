class Solution {
    int lps(const string& s, int i, int j, vector<vector<int>>& DP) {
        if (i == j) return 1;
        if (i > j) return 0;

        if (!DP[i][j])
            if (s[i] == s[j])
                DP[i][j] = lps(s, i + 1, j - 1, DP) + 2;
            else
                DP[i][j] = max(lps(s, i + 1, j, DP), lps(s, i, j - 1, DP));

        return DP[i][j];
    }

public:
    int longestPalindromeSubseq(string s) {
        vector DP(s.size(), vector<int>(s.size(), 0));
        return lps(s, 0, s.size() - 1, DP);
    }

    int longestPalindromeSubseq_DP(string s) {
        int n = s.size();
        int DP[n][n];

        for (int i = 0; i < n; ++i)
            DP[i][i] = 1;

        for (int l = 2; l <= n; ++l) {
            for (int i = 0; i + l - 1 < n; ++i) {
                int j = i + l - 1;
                if (s[i] == s[j])
                    DP[i][j] = (l == 2) ? 2 : DP[i + 1][j - 1] + 2;
                else
                    DP[i][j] = max(DP[i + 1][j], DP[i][j - 1]);
            }
        }

        return DP[0][n - 1];
    }
};
