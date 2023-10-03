class Solution {
    int64_t dfs(vector<int>& nums, int n, vector<int64_t>& memo) {
        if (n == 0)
            return 1;

        if (n < nums[0])
            return 0;

        if (memo[n] != -1)
            return memo[n];

        int64_t count = 0;
        for (auto num : nums) {
            if (num > n)
                break;
            count += dfs(nums, n - num, memo);
        }

        return memo[n] = count;
    }

public:
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int64_t> memo(target + 1, -1);
        return dfs(nums, target, memo);
    }

    int combinationSum4_dp(vector<int>& nums, int target) {
        unsigned int dp[1001] =  {0};
        dp[0] = 1;

        for (int i = 1; i <= target; ++i)
            for (auto num : nums)
                if (i - num > -1)
                    dp[i] += dp[i - num];

        return dp[target];
        
    }
};

/*
1 0 0 0 0
1 1 0 0 0
1 1 2 0 0
1 1 2 4 0
1 1 2 4 7
*/
