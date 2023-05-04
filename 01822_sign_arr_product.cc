class Solution {
public:
    int arraySign(vector<int>& nums) {
        int ans = 1;
        for (auto n : nums)
            if (n == 0) return 0;
            else ans *= (n < 0 ? -1 : 1);
        return ans;
    }
};
