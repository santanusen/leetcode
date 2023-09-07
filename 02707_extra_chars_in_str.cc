class Solution {
    int dfs(const string& s, unordered_set<string>& dict, int spos, int cpos, vector<vector<int>>& dp) {
        if (cpos == s.size())
            return (cpos - spos);

        if (dp[spos][cpos] != -1)
            return dp[spos][cpos];

        int sublen = cpos - spos + 1;
        int snew = dfs(s, dict, cpos + 1, cpos + 1, dp) +
                    (dict.find(s.substr(spos, sublen)) != dict.end() ? 0 : sublen);
        int scont = dfs(s, dict, spos, cpos + 1, dp);

        return dp[spos][cpos] = min(snew, scont);
    }

public:
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> dict(dictionary.begin(), dictionary.end());
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));

        return dfs(s, dict, 0, 0, dp);    
    }
};
