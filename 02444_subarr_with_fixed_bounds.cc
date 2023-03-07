class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int rmin = -1, rmax = -1, roor = -1;
        long long ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            auto n = nums[i];
            if (n < minK || n > maxK)
                roor = i;
            else {
                if (n == minK) rmin = i;
                if (n == maxK) rmax = i;
                ans += max(0, min(rmin, rmax) - roor);
            }
        }
        return ans;
    }
}
