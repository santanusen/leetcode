class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (int i = 0; i < nums.size();) {
            int x = nums[i];
            if (x > 0 && x < nums.size() + 1 && x != nums[x - 1])
                swap(nums[i], nums[x - 1]);
            else
                ++i;
        }

        for (int i = 0; i < nums.size(); ++i)
            if (nums[i] != i + 1)
                return i + 1;

        return nums.size() + 1;
    }
};
