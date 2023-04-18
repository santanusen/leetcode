class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long long ans = 0, psum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            psum += nums[i];
            auto ceil_avg = (psum + i) / (i + 1);
            ans = max (ans, ceil_avg);
        }
        return ans;
    }

};
