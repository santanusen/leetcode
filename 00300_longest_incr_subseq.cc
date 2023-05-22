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
};
