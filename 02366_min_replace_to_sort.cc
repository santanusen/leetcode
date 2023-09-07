class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size(), nmin = nums[n - 1], b;
        for (int i = n - 2; i > -1; --i) {
            b = nums[i];
            if (b <= nmin)
                nmin = b;
            else {
                int d = b / nmin;
                if (b % nmin) {
                    ans += d;
                    nmin = b / (d + 1);
                } else
                    ans += (d - 1);
            }
        }

        return ans;        
    }
};

auto _ = [](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
