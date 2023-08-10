class Solution {
    bool has_pairs(vector<int>& nums, int p, int diff) {
        int c = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (2 * (p - c) > (nums.size() - i + 1))
                break;
            if (nums[i] - nums[i - 1] <= diff) {
                if (++c >= p)
                    return true;
                ++i;
            }
        }

        return false;
    }

public:
    int minimizeMax(vector<int>& nums, int p) {
        if (p == 0) return 0;
        if (nums.size() < 2) return 0;
        sort(nums.begin(), nums.end());
        int l = 0, r = nums[nums.size() - 1] - nums[0];

        while (l <= r) {
            int m = l + (r - l) / 2;
            if (!has_pairs(nums, p, m))
                l = m + 1;
            else
                r = m - 1; 
        }

        return l;
    }
};

class Solution_DP {
    int dfs(vector<int>& nums, int p, int pos, vector<vector<int>>& memo) {
        if (p == 0) return 0;
        if (pos >= nums.size()) return INT_MAX;

        if (memo[pos][p - 1] != -1) return memo[pos][p - 1];

        int inc = max(dfs(nums, p - 1, pos + 2, memo),
                      nums[pos] - nums[pos - 1]);
        int exc = dfs(nums, p, pos + 1, memo);

        return memo[pos][p - 1] = min(inc, exc);
    }

public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        vector memo(nums.size(), vector(p, -1));

        return dfs(nums, p, 1, memo);
    }
};

auto _ = [](){ios::sync_with_stdio(false); cin.tie(0); cout.tie(0); return 0;}();
