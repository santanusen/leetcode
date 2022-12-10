class Solution {
    typedef long INT;
public:
    int minimumAverageDifference(vector<int>& nums) {
        INT total = 0;
        for (int i = 0; i < nums.size(); ++i)
            total += nums[i];
        
        INT mad = LONG_MAX, psum = 0;
        int mi = -1;
        for (int i = 0; i < nums.size(); ++i) {
            psum += nums[i];
            INT avd = abs((INT)(psum / (i + 1) -
                              (((i + 1 < nums.size()) ? ((total - psum) / (nums.size() - i - 1)) : 0))));
            if (avd < mad) {
                mad = avd;
                mi = i;
            }
        }
        
        return mi;
        
    }
};
