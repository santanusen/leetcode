class Solution {
public:
    vector<int> shuffle_inplace(vector<int>& nums, int n) {
        for (int i = 0; i < n; ++i)
            nums[i + n] |= (nums[i] << 16);

        for (int i = 0, j = n; j < nums.size(); ++j) {
            nums[i++] = nums[j] >> 16;
            nums[i++] = nums[j] & 0xffff;
        }

        return nums;
    }

    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> res(n << 1);
        for (int i = 0; i < n; ++i) {
            res[i << 1] = nums[i];
            res[(i << 1) | 1] = nums[i + n];
        }
        return res;
    }
};
