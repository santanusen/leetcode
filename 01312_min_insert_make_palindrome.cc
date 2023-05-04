class Solution {
    int dfs(const string& s, int i, int j, vector<vector<int>>& DP) {
        if (i >= j) return 0;
        if (DP[i][j] != -1) return DP[i][j];

        if (s[i] == s[j])
            return (DP[i][j] = dfs(s, i + 1, j - 1, DP));
        
        return (DP[i][j] = 1 + min(dfs(s, i + 1, j, DP), dfs(s, i , j - 1, DP)));
    }

public:
    int minInsertions(string s) {
        vector DP(s.size(), vector<int>(s.size(), 0));

        for (int d = 1; d <= s.size(); ++d)
            for (int i = s.size() - d - 1; i > -1; --i) {
                int j = i + d;
                if (s[i] == s[j])
                    DP[i][j] = DP[i + 1][j - 1];
                else
                    DP[i][j] = 1 + min(DP[i + 1][j], DP[i][j - 1]);
            }

        return DP[0][s.size() - 1];

        //vector DP(s.size(), vector<int>(s.size(), -1));
        //return dfs(s, 0, s.size() - 1, DP);       
    }
};
