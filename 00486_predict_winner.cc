class Solution {
    int dfs(vector<int>& nums, int l, int r, vector<vector<int>>& memo) {
        if (l == r) return nums[l];
        if (memo[l][r] != -1) return memo[l][r];

        int sl = dfs(nums, l + 1, r, memo);
        int sr = dfs(nums, l, r - 1, memo);

        int turn = nums.size() - (r - l) - 1;
        return memo[l][r] = (turn % 2 ? min(sl, sr) : max(nums[l] + sl, nums[r] + sr));
    }

public:
    bool PredictTheWinner(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);

        int n = nums.size();
        //vector memo = vector(n, vector<int>(n));
        int memo[n][n];
        for (int i = 0; i < n; ++i)
            memo[i][i] = nums[i];

        for (int d = 1; d < n; ++d) {
            int lmax = n - d;
            for (int l = 0; l < lmax; ++l) {
                int r = l + d;
                memo[l][r] = (((n - d - 1) % 2) ?
                                min(memo[l + 1][r], memo[l][r - 1]) :
                                max(nums[l] + memo[l + 1][r], nums[r] + memo[l][r - 1]));
            }
        }

        int smax = memo[0][n - 1];
        return (smax >= total - smax);       
    }

    bool PredictTheWinner_dfs(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);

        vector memo = vector(nums.size(), vector<int>(nums.size(), -1));
        int smax = dfs(nums, 0, nums.size() - 1, memo);

        return (smax >= total - smax);
        
    }

};

