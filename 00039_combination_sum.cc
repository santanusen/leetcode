class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<vector<int>>> dp(target + 1, vector<vector<int>>());
        dp[0].push_back(vector<int>());

        for (auto c : candidates) {
            for (int i = 0; i + c <= target; ++i)
                for (auto vec : dp[i]) {
                    vec.push_back(c);
                    dp[i + c].push_back(vec);
                }
        }

        return dp[target];
    }
};
