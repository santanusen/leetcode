static const int __ = []() { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; }();
class Solution {
    long long dfs(vector<vector<int>>& ques, int i, vector<long long>& memo) {
        if (i >= ques.size()) return 0;
        if (memo[i] != -1) return memo[i];

        return memo[i] = max(dfs(ques, i + 1, memo),
                             dfs(ques, i + 1 + ques[i][1], memo) + ques[i][0]);

    }
public:
    long long mostPoints(vector<vector<int>>& questions) {
        /*
        vector<long long> memo(questions.size(), -1);
        return dfs(questions, 0, memo);
        */
        int n = questions.size();
        long long dp[n];
        dp[n - 1] = questions[n - 1][0];
        for (int i = n - 2; i > -1; --i)
            dp[i] = max(dp[i + 1],
                        questions[i][0] +
                        ((i + 1 + questions[i][1] < n) ? dp[i + 1 + questions[i][1]] : 0));

        return dp[0];
        
    }
};
