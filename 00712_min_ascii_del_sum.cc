class Solution {
    int lcs_min_del(const string& s1, const string& s2, int p1, int p2, vector<vector<int>>& dp) {
        if (p1 >= s1.size() && p2 >= s2.size())
            return 0;

        if (p1 >= s1.size()) {
            int ans = 0;
            for (int i = p2; i < s2.size(); ++i)
                ans += static_cast<int>(s2[i]);
            return ans;
        }

        if (p2 >= s2.size()) {
            int ans = 0;
            for (int i = p1; i < s1.size(); ++i)
                ans += static_cast<int>(s1[i]);
            return ans;
        }

        if (dp[p1][p2] != -1)
            return dp[p1][p2];

        if (s1[p1] == s2[p2])
            return dp[p1][p2] = lcs_min_del(s1, s2, p1 + 1, p2 + 1, dp);
        
        return dp[p1][p2] =
                min(static_cast<int>(s1[p1]) + lcs_min_del(s1, s2, p1 + 1, p2, dp),
                    static_cast<int>(s2[p2]) + lcs_min_del(s1, s2, p1, p2 + 1, dp));
    }

public:
    int minimumDeleteSum_rec(string s1, string s2) {
        vector dp(s1.size(), vector<int>(s2.size(), -1));
        return lcs_min_del(s1, s2, 0, 0, dp);
    }

    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        int dp[m + 1][n + 1];

        dp[m][n] = 0;

        for (int i = m - 1; i > -1; --i)
            dp[i][n] = dp[i + 1][n] + s1[i];

        for (int j = n - 1; j > -1; --j)
            dp[m][j] = dp[m][j + 1] + s2[j];

        for (int i = m - 1; i > -1; --i)
            for (int j = n - 1; j > -1; --j)
                dp[i][j] = ((s1[i] == s2[j]) ?
                            dp[i + 1][j + 1] :
                            min(s1[i] + dp[i + 1][j], s2[j] + dp[i][j + 1]));

        return dp[0][0];
    }

    int minimumDeleteSum2(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        int dp[m + 1][n + 1];

        dp[0][0] = 0;

        for (int i = 1; i <= m; ++i)
            dp[i][0] = dp[i - 1][0] + s1[i - 1];

        for (int j = 1; j <= n; ++j)
            dp[0][j] = dp[0][j - 1] + s2[j - 1];

        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= n; ++j)
                dp[i][j] = ((s1[i - 1] == s2[j - 1]) ?
                            dp[i - 1][j - 1] :
                            min(s1[i - 1] + dp[i - 1][j], s2[j - 1] + dp[i][j - 1]));

        return dp[m][n];
    }

};

auto _ = [](){ios::sync_with_stdio(false); cin.tie(0); cout.tie(0); return 0;}();
