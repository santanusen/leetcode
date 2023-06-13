class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        for (int l = 0, r = 1; r <= nums.size(); ++r)
            if (r == nums.size() || nums[r] != nums[r - 1] + 1) {
                ans.push_back((nums[r - 1] != nums[l]) ? to_string(nums[l]) + "->" + to_string(nums[r - 1]) : to_string(nums[l]));
                l = r;
            }
        return ans;
    }
};
