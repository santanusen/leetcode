class Solution {
    const int M = 1E9 + 7;
    int dfs(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& memo) {
        if (memo[i][j] != 0) return memo[i][j];

        int ans = 1;

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        for (int d = 0; d < 4; ++d) {
            int x = i + dx[d], y = j + dy[d];
            if (x > -1 && x < grid.size() && y > -1 && y < grid[0].size() && grid[x][y] > grid[i][j])
                ans = (ans + dfs(grid, x, y, memo)) % M;
        }
        return memo[i][j] = ans;
    }

public:
    int countPaths(vector<vector<int>>& grid) {

        vector<pair<int, int>> order;
        for (int i = 0; i < grid.size(); ++i)
            for (int j = 0; j < grid[i].size(); ++j)
                order.push_back({i, j});
                
        sort(order.begin(), order.end(),
             [&](const pair<int, int>& a, const pair<int, int>& b) -> bool {
                 return grid[a.first][a.second] < grid[b.first][b.second];
                 }
            );

        vector<vector<int>> memo(grid.size(), vector<int>(grid[0].size(), 1));

        int ans = 0;
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        for (auto [i, j] : order) {
            for (int d = 0; d < 4; ++d) {
                int x = i + dx[d], y = j + dy[d];
                if (x > -1 && x < grid.size() && y > -1 && y < grid[0].size() && grid[i][j] < grid[x][y])
                    memo[x][y] = (memo[x][y] + memo[i][j]) % M;
            }
            ans = (ans + memo[i][j]) % M;
        }

        return ans;
    
    }

    int countPaths_dfs(vector<vector<int>>& grid) {
        vector<vector<int>> memo(grid.size(), vector<int>(grid[0].size(), 0));

        int ans = 0;

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (memo[i][j] == 0)
                    memo[i][j] = dfs(grid, i, j, memo);

                ans = (ans + memo[i][j]) % M;
            }
        }

        return ans;
        
    }
};
