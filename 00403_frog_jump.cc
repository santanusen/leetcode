class Solution {
    int binsearch(vector<int>& stones, int k, int l) {
        int r = stones.size() - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            int x = stones[m];

            if (x == k)
                return m;
            if (x < k)
                l = m + 1;
            else
                r = m - 1;
        }

        return -1;
    }

    int8_t dfs(vector<int>& stones, int i, int k, vector<vector<int8_t>>& dp) {
        if (i == stones.size() - 1)
            return 1;

        if (dp[i][k] != -1)
            return dp[i][k];

        int step[] = {-1, 0, 1};
        for (int s : step) {
            int kk = k + s;
            int j;
            if (kk > 0 && (j = binsearch(stones, stones[i] + kk, i + 1)) != -1)
                if (dfs(stones, j, kk, dp))
                    return dp[i][k] = 1;
        }

        return dp[i][k] = 0;
    }

public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        vector<vector<int8_t>> dp(n, vector<int8_t>(n + 1, -1));
        return dfs(stones, 0, 0, dp) == 1;
    }
};

auto _ = [](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
