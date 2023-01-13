class Solution {
public:
    int search(vector<int>& nums, int target) {

        if (target == nums[0]) return 0; // Optimization only.
        
        int l = 0, r = nums.size() - 1;

        while (l < r) {
            int m = l + (r - l + 1) / 2; // ensure m != l
            if (nums[m] == target) return m;

            // target and mid are on the same side
            if ((nums[m] - nums[0]) * (target - nums[0]) > 0) {
                // Regular binary search logic
                if (nums[m] > target)
                    r = m - 1;
                else
                    l = m;
            } else {
                if (target < nums[0]) // 0 ... m ...  Pivot ... target ... N 
                    l = m;
                else // 0 ... target ... Pivot ... m ... N
                    r = m - 1;
            }
        }

        return (nums[r] == target) ? r : -1;
        
    }
};
