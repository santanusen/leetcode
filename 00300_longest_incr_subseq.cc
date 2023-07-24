static const int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int lis[nums.size()], ll = 0;
        for (auto n : nums) {
            int idx = lower_bound(&lis[0], &lis[ll], n) - &lis[0];
            if (idx == ll) ++ll;
            lis[idx] = n;
        }
        return ll;
    }

    int lengthOfLIS_DP(vector<int>& nums) {
        int n = nums.size();
        int lis[n];
        lis[0] = 1;

        int ans = 1;
        for (int i = 1; i < n; i++) {
            lis[i] = 1;
            for (int j = 0; j < i; j++)
                if (nums[i] > nums[j] && lis[i] < lis[j] + 1)
                    lis[i] = lis[j] + 1;
            ans = max(ans, lis[i]);
        }

        return ans;
    }
};
