class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = INT_MIN, n = nums.size(), imax = n >> 1;
        --n;
        for (int i = 0; i < imax; ++i)
            ans = max(ans, nums[i] + nums[n - i]);
        return ans;
    }
};

auto _ = [](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
