class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i + 2 < nums.size(); ++i) {
            int tgt = -nums[i];
            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                int sum = nums[l] + nums[r];
                if (sum < tgt) ++l;
                else if (sum > tgt) --r;
                else {
                    res.push_back(vector<int>{nums[i], nums[l], nums[r]});
                    while (l < r && nums[l] == nums[l + 1]) ++l;
                    ++l;
                    while (l < r && nums[r] == nums[r - 1]) --r;
                    --r;
                }
            }
            while (i + 1 < nums.size() && nums[i] == nums[i + 1]) ++i;
        }
        return res;
    }
};
