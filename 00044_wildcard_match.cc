class Solution {
    
public:
    bool isMatch(string sxx, string pxx) {
        const char *s = sxx.c_str(), *p = pxx.c_str();
        const char *ss = s, *star = NULL;

        while (*s) {
            if (*p == *s || *p == '?') {++p; ++s; continue;} // Char match, advance both.
            if (*p == '*') {star = p++; ss = s; continue;} // Track star index, advance pattern ptr.
            if (star) {p = star + 1; s = ++ss; continue;} // Last pattern *, chars mismatch. Let last star match till here.

            return false; // Chars mismatch, not in star.
        }

        while (*p == '*') ++p;
        return !*p;
    }

public:
    bool isMatch_dp(string s, string p) {
        vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, false));
        dp[0][0] = true;
        for (int j = 0; j < p.size() && p[j] == '*'; ++j)
            dp[0][j + 1] = true;

        for (int i = 1; i <= s.size(); ++i)
            for (int j = 1; j <= p.size(); ++j)
                if (p[j - 1] == '*')
                    dp[i][j] = dp[i - 1][j] || dp[i][j -1];
                else
                    dp[i][j] = (s[i - 1] == p[j - 1] || '?' == p[j - 1]) && dp[i - 1][j - 1];

        return dp[s.size()][p.size()];      
    }
};
