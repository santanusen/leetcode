class Solution {
    int dfs(vector<int>& nums1, vector<int>& nums2, int i, int j, vector<vector<int>>& memo) {
        if (i >= nums1.size() || j >= nums2.size()) return 0;
        if (memo[i][j] != -1) return memo[i][j];

        if (nums1[i] == nums2[j])
            memo[i][j] = 1 + dfs(nums1, nums2, i + 1, j + 1, memo);
        else
            memo[i][j] = max(dfs(nums1, nums2, i, j + 1, memo),
                             dfs(nums1, nums2, i + 1, j, memo));
        return memo[i][j];
    }
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        /*vector<vector<int>> memo(nums1.size(), vector<int>(nums2.size(), -1));
        return dfs(nums1, nums2, 0, 0, memo);*/

        int M = nums1.size(), N = nums2.size();
        int dp[M + 1][N + 1];
        for (int i = M; i > -1; --i) {
            for (int j = N; j > -1; --j) {
                if (i == M || j == N)
                    dp[i][j] = 0;
                else if (nums1[i] == nums2[j])
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                else
                    dp[i][j] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }

        return dp[0][0];

    }
};
