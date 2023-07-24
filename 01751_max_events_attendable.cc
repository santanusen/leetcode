class Solution {
    int dfs(vector<vector<int>>& events, int pos, int k, vector<vector<int>>& memo) {
        if (pos == events.size() || k <= 0)
            return 0;

        if (memo[pos][k] != -1)
            return memo[pos][k];
        
        int vmax = dfs(events, pos + 1, k, memo);

        int val = events[pos][2], tend = events[pos][1];
        int pos2 = pos + 1;
        while (pos2 < events.size() && events[pos2][0] <= tend)
            ++pos2;

        vmax = max(vmax, val + dfs(events, pos2, k - 1, memo));

        return memo[pos][k] = vmax;
    }

public:
    int maxValue(vector<vector<int>>& events, int k) {

        sort(events.begin(), events.end());

#if 1        
        // Top-Down
        vector<vector<int>> memo(events.size(), vector<int>(k + 1, -1));
        return dfs(events, 0, k, memo);
#else
        // Bootom-Up
        int ans = 0;

        vector<vector<int>> memo(events.size() + 1, vector<int>(k + 1, 0));

        for (int kk = 1; kk <= k; ++kk) {
            for (int pos = events.size() - 1; pos > -1; --pos) {
                int vmax = memo[pos + 1][kk];

                int val = events[pos][2], tend = events[pos][1];
                int pos2 = pos + 1;
                while (pos2 < events.size() && events[pos2][0] <= tend)
                    ++pos2;
                vmax = max(vmax, val + memo[pos2][kk - 1]);
                ans = max(ans, vmax);
                memo[pos][kk] = vmax;
            }
        }

        return ans;
#endif
        
    }
};

auto _ = [](){ios::sync_with_stdio(false); cin.tie(0); cout.tie(0); return false;}();
