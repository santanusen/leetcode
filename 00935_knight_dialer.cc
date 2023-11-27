class Solution {
public:
    int knightDialer(int n) {
        if (n == 1) return 10;

#if 0
        int dpad[4][3] = {
            {1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {-1, 0, -1}
        };

        vector<int> adj[10] = {};
        pair<int, int> dd[] = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1},
                          {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};

        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 3; ++j) {
                int v = dpad[i][j];
                if (v < 0)
                    continue;
                for (auto [dx, dy] : dd) {
                    int x = i + dx, y = j + dy;
                    if (x > -1 && x < 4 && y > -1 && y < 3 && dpad[x][y] > -1)
                        adj[v].push_back(dpad[x][y]);
                }
            }
#else
        vector<int> adj[] = {
            {4, 6},
            {6, 8}, {7, 9}, {4, 8},
            {0, 3, 9}, {}, {0, 1, 7},
            {2, 6}, {1, 3}, {4, 2} 
        };
#endif

        int dp[2][10] = {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

        int M = 1E9 + 7;
        for (int i = 1; i < n; ++i) {
            int cur = i % 2, prv = (i - 1) % 2;
            memset(dp[cur], 0, sizeof(dp[cur]));

            for (int dig = 0; dig < 10; ++dig) {
                for (auto dnxt : adj[dig]) {
                    dp[cur][dnxt] = (dp[prv][dig] + dp[cur][dnxt]) % M;
                }
            }
        }

        int ans = 0, idx = (n - 1) % 2;
        for (int dig = 0; dig < 10; ++dig) {
            ans = (ans + dp[idx][dig]) % M;
        }

        return ans;
        
    }
};

auto _ = [](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
