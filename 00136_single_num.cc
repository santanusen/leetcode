class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int r = 0;
        for (auto n : nums)
            r ^= n;
        return r;
    }
};
