class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() > 1)
            nums[nums.size() - 2] = max(nums[nums.size() - 2], nums[nums.size() - 1]);

        for (int i = int(nums.size()) - 3; i > -1; --i)
            nums[i] = max(nums[i + 1], nums[i] + nums[i + 2]);
        
        return nums[0];
    }
};
