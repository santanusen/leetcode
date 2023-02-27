class Solution {
public:
    int minDistance(string word1, string word2) {
        int N1 = word1.size(), N2 = word2.size();
        if (N1 == 0) return N2;
        if (N2 == 0) return N1;
        //vector<vector<int>> dp (N1 + 1, vector<int>(N2 + 1));
        int dp[N1 + 1][N2 + 1];
        dp[0][0] = 0;
        for (int i = 1; i <= N1; ++i)
            dp[i][0] = i;
        for (int j = 1; j <= N2; ++j)
            dp[0][j] = j;

        for (int i = 1; i <= N1; ++i)
            for (int j = 1; j <= N2; ++j)
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = 1 + min(dp[i - 1][j - 1],
                                       min(dp[i][j - 1], dp[i - 1][j]));

        return dp[N1][N2];
        
    }
};
