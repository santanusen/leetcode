class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        if (nums.size() < 3)
            return true;

        bool inc = false, dec = false;
        int prv = nums[0];
        for (auto cur : nums) {
            if (cur < prv)
                dec = true;
            else if (cur > prv)
                inc = true;
            if (inc && dec)
                return false;
            prv = cur;
        }

        return true;
    }
};

auto _=[](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
