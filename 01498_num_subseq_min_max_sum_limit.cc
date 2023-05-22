static const int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
    const int MOD = 1E9 + 7;
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int power[nums.size()];
        power[0] = 1;
        for (int i = 1; i < nums.size(); ++i) {
            power[i] = (power[i - 1] << 1);
            if (power[i] >= MOD)
                power[i] -= MOD;
        }
        int l = 0, r = nums.size() - 1;
        int ans = 0;
        while (l <= r) {
            if (nums[l] + nums[r] <= target) {
                if ((ans = (ans + power[r - l])) >= MOD)
                    ans -= MOD;
                ++l;
            } else
                --r;
        }
        return ans;
    }
};
