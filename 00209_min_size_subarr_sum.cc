class Solution {
    bool satisfySub(vector<int>& psum, int target, int len) {
        int l = 0, r = len - 1;
        while (r < psum.size()) {
            int wsum = psum[r] - (l > 0 ? psum[l - 1] : 0);
            if (wsum >= target)
                return true;
            ++r; ++l;
        }

        return false;
    }

public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int N = nums.size();
        for (int i = 1; i < N; ++i)
            nums[i] += nums[i - 1];

        if (nums[N - 1] < target)
            return 0;

        int l = 1, r = N;
        while (l <= r) {
            int m = (l + r) / 2;
            if (satisfySub(nums, target, m)) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return l;
    }
};

class Solution_SlWin {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int N = nums.size();
        int l = 0, r = 0, sum = 0, ans = N + 1;

        while (r < N || (sum >= target && l < N)) {
            if (sum < target) {
                sum += nums[r];
                ++r;
            } else {
                ans = min(ans, r - l);
                sum -= nums[l];
                ++l;
            }
        }

        return (ans > N ? 0 : ans);
    }
};

auto _ = [](){ios::sync_with_stdio(false); cin.tie(0); cout.tie(0); return 0;}();
