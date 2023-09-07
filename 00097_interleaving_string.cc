class Solution {
    bool dfs(string& s1, string& s2, string& s3, int p1, int p2, int dp[][101]) {
        if (p1 + p2 >= s3.size()) return true;

        if (dp[p1][p2] != 0)
            return dp[p1][p2] - 1;

        if (p1 < s1.size() && s1[p1] == s3[p1 + p2])
            if (dfs(s1, s2, s3, p1 + 1, p2, dp))
                return (dp[p1][p2] = 2) - 1;
        
        if (p2 < s2.size() && s2[p2] == s3[p1 + p2])
            if (dfs(s1, s2, s3, p1, p2 + 1, dp))
                return (dp[p1][p2] = 2) - 1;

        return (dp[p1][p2] = 1) - 1;
    }

public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) return false;
#if 0
        vector dp(s1.size() + 1, vector<int>(s2.size() + 1, -1));
        int dp[101][101] = {{0}};
        return dfs(s1, s2, s3, 0, 0, dp);
#else
        vector<vector<bool>> dp(s1.size() + 1, vector<bool>(s2.size() + 1, false));
        for (int p1 = s1.size(); p1 > -1; --p1)
            for (int p2 = s2.size(); p2 > -1; --p2)
                dp[p1][p2] = ((p1 + p2 >= s3.size()) ||
                    (p1 < s1.size() && s1[p1] == s3[p1 + p2] && dp[p1 + 1][p2]) ||
                    (p2 < s2.size() && s2[p2] == s3[p1 + p2] && dp[p1][p2 + 1]));

        return dp[0][0];
#endif
    }
};

auto _ = [](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
