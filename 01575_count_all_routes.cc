class Solution {
    const int M = 1E9 + 7;
    int dfs(vector<int>& locations, int cur, int end, int fuel, vector<vector<int>>& memo) {
        if (fuel < 0) return 0;

        if (memo[cur][fuel] != -1) return memo[cur][fuel];

        int ans = (cur == end ? 1 : 0);
        for (int i = 0; i < locations.size(); ++i) {
            if (i != cur)
                ans = (ans + dfs(locations, i, end, fuel - abs(locations[cur] - locations[i]), memo)) % M;
        }

        return memo[cur][fuel] = ans;
    }

public:
    int countRoutes_dfs(vector<int>& locations, int start, int finish, int fuel) {
        vector<vector<int>> memo(locations.size(), vector<int>(fuel + 1, -1));
        return dfs(locations, start, finish, fuel, memo);
    }

    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int dp[locations.size()][fuel + 1];

        for (int f = 0; f <= fuel; ++f) {
            for (int cur = 0; cur < locations.size(); ++cur) {
                dp[cur][f] = (cur == finish ? 1 : 0);
                if (f == 0) continue;
                for (int k = 0; k < locations.size(); ++k) {
                    if (cur != k) {
                        int fleft = f - abs(locations[cur] - locations[k]);
                        if (fleft > -1)
                            dp[cur][f] = (dp[cur][f] + dp[k][fleft]) % M;
                    }
                }
            }
        }

        return dp[start][fuel];
    }
};
