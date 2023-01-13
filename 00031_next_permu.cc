// https://www.nayuki.io/page/next-lexicographical-permutation-algorithm
// https://en.wikipedia.org/wiki/Permutation#Generation_in_lexicographic_order

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        while (i > -1 && !(nums[i] < nums[i + 1])) --i;
        if (i > -1) {
            int j = nums.size() - 1;
            while (j > i && !(nums[j] > nums[i])) --j;
            swap(nums[i], nums[j]);  
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};
