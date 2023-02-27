class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;

        while (l < r) {
            int m = (l + r) >> 1;
            if (!((r - m) & 0x1)) { // Left half has odd size
                if (nums[m] == nums[m + 1]) // split
                    l = m;
                else
                    r = m;
            } else { // Left has even size
                if (nums[m] == nums[m + 1]) // split
                    r = m - 1;
                else
                    l = m + 1;
            }
        }

        return nums[l];
        
    }
};
