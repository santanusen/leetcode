
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int tgt = accumulate(nums.begin(), nums.end(), 0) - x;
        if (tgt < 0)
            return -1;
        if (tgt == 0)
            return n;

        int wmax = 0, l = 0, r = 0, s = 0;
        while (!(r == n && s < tgt)) {
            if (tgt == s)
                wmax = max(wmax, r - l);

            if (s >= tgt)
                s -= nums[l++];
            else
                if (r < n)
                    s += nums[r++];
        }

        if (wmax == 0)
            return -1;

        return (n - wmax);

    }

};

class Solution_DP_MLE {
    int dfs(vector<int>& pref, int x, int l, int r, vector<vector<int>>& dp) {
        int n = pref.size();
        
        if (l > r)
            return n + 1;

        int psum = (l > 0 ? pref[l - 1] : 0);
        int ssum = pref[n - 1] - pref[r];
        int tot = psum + ssum;

        if (tot == x)
            return 0;

        if (tot > x)
            return n + 1;

        if (dp[l][r] != -1)
            return dp[l][r];

        int res = dfs(pref, x, l + 1, r, dp);
        if (l != r)
            res = min(res, dfs(pref, x, l, r - 1, dp));

        return dp[l][r] = 1 + res;

    }

public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        
        // Prefix sum.
        for (int i = 1; i < n; ++i)
            nums[i] += nums[i - 1];

        if (x > nums[n - 1])
            return -1;

        if (x == nums[n - 1])
            return n;

        vector dp(n, vector<int>(n, -1));
        int ans = dfs(nums, x, 0, n - 1, dp);

        return (ans > n ? -1 : ans);
        
    }
};

auto _ = [](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
