class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int msum = INT_MIN, csum = -1;
        for (auto num : nums) {
            csum = max(num, num + csum);
            if (csum > msum) msum = csum;
        }
        return msum;
    }

    int maxSubArray2(vector<int>& nums) {
        int msum = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            nums[i] = max(nums[i], nums[i] + nums[i - 1]);
            msum = max(msum, nums[i]);
        }
        return msum;
    }
};
