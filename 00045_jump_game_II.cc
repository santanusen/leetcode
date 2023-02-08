class Solution {
public:
    int jump(vector<int>& nums) {
        int jmps = 0, cend = 0, cfar = 0, n = nums.size() - 1;
        for (int i = 0; i < n; ++i) {
            cfar = max(cfar, i + nums[i]);
            if (i == cend) {
                ++jmps;
                cend = cfar;
            }
        }

        return jmps;
    }

    int jump_dp(vector<int>& nums) {
        vector<int> dp(nums.size(), INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < nums.size(); ++i)
            for (int j = 1; j <= nums[i] && i + j < nums.size(); ++j)
                dp[i + j] = min(dp[i + j], dp[i] + 1);

        return dp[nums.size() - 1];
    }
};
