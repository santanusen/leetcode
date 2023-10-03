class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        for (int i = 0, j = 0; j < nums.size(); ++j)
            if (!(nums[j] & 1))
                swap(nums[i++], nums[j]);

        return nums;
    }

    vector<int> sortArrayByParity2(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;
        while (i < j) {
            while (i < j && !(nums[i] & 1))
                ++i;
            while (i < j && (nums[j] & 1))
                --j;
            if (i < j)
                swap(nums[i], nums[j]);
        }

        return nums;
    }
};

auto _=[](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
