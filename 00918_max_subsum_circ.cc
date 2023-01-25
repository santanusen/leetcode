class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        
        int max_sasum = nums[0], min_sasum = nums[0], sum = nums[0];

        for (int i = 1, cur_smax = nums[0], cur_smin = nums[0]; i < nums.size(); ++i) {
            sum += nums[i];

            // Kadane's min subarray sum.
            cur_smin = min(nums[i], nums[i] + cur_smin);
            min_sasum = min(min_sasum, cur_smin);

            // Kadane's max subarray sum.
            cur_smax = max(nums[i], nums[i] + cur_smax);
            max_sasum = max(max_sasum, cur_smax);
        }

        return (max_sasum < 0) ? max_sasum : max(max_sasum, sum - min_sasum);
        
    }
};
