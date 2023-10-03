class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if (nums.size() < 3)
            return false;
        int m = INT_MIN;
        stack<int> stk;
        for (int i = nums.size() - 1; i > -1; --i) {
            int cur = nums[i];
            while (!stk.empty() && cur > stk.top()) {
                m = stk.top();
                stk.pop();
            }

            if (cur < m)
                return true;

            stk.push(cur);
        }

        return false;
    }
};

auto _ = [](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
