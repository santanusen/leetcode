class Solution {
    int rev(int num) {
        int r = 0;
        while (num) {
            r = r * 10 + num % 10;
            num /= 10;
        }
        return r;
    }

public:
    int countNicePairs(vector<int>& nums) {
        int M = 1E9 + 7;
        unordered_map<int, int> tbl;
        int ans = 0;
        for (auto num : nums)
            ans = (ans + tbl[num - rev(num)]++) % M;
        return ans;
    }
};

auto _ = [](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
