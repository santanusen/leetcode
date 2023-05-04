static const int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans(2, vector<int>());
        vector<bool> ht1(2001, false), ht2(2001, false);
        for (auto n : nums1) ht1[1000 + n] = true;
        for (auto n : nums2) ht2[1000 + n] = true;
        for (int i = 0; i < 2001; ++i)
            if (ht1[i] && !ht2[i])
                ans[0].push_back(i - 1000);
            else if (!ht1[i] && ht2[i])
                ans[1].push_back(i - 1000);

        return ans;
    }
};
