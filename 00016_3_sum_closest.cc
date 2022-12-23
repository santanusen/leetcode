class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closest = 10e5;
        sort(nums.begin(), nums.end());
        for (int i = 0; i + 2 < nums.size(); ++i) {
            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == target) return target;

                if (abs(sum - target) < abs(closest - target))
                    closest = sum;
                
                if (sum < target) ++l;
                else --r;
            }
            while (i + 1 < nums.size() && nums[i] == nums[i + 1]) ++i;
        }
        return closest;
    }
};
