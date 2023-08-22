class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n + 1);
        dp[0] = true;

        for (int i = 0; i < n; ++i) {
            int di = i + 1;
            if (i > 0 && nums[i] == nums[i - 1])
                dp[di] = dp[di] || dp[di - 2];

            if ((i > 1) && ((nums[i] == nums[i - 1] && nums[i] == nums[i - 2]) ||
                (nums[i] == nums[i - 1] + 1 && nums[i] == nums[i - 2] + 2)))
                dp[di] = dp[di] || dp[di - 3];
        }

        return dp[n];
        
    }
};

auto _ = [](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
