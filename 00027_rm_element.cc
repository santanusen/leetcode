class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        int i = 0, j = nums.size() - 1;
        
        while (i <= j) {
            while (i <= j && nums[i] != val)
                ++i;
            while (i <= j && nums[j] == val)
                --j;
            
            if (i < j)
                swap(nums[i], nums[j]);
        }
        
        return i;
    }
};
