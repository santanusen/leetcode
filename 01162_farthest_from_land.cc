class Solution {
    void flood(int x0, int y0, int x1, int y1, vector<vector<int>>& grid, vector<vector<int>>& dist) {
        if (x1 < 0 || x1 >= grid.size() || y1 < 0 || y1 >= grid.size())
            return;

        int d = abs(x0 - x1) + abs(y0 - y1);
        if ((d == 0) || (grid[x1][y1] == 0 && d < dist[x1][y1])) {
            dist[x1][y1] = d;
            flood(x0, y0, x1 + 1, y1, grid, dist);
            flood(x0, y0, x1 - 1, y1, grid, dist);
            flood(x0, y0, x1, y1 + 1, grid, dist);
            flood(x0, y0, x1, y1 - 1, grid, dist);
        }
    }

public:
    int maxDistance(vector<vector<int>>& grid) {
        const int n = grid.size(), DMAX = n * n + 1;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j])
                    grid[i][j] = 0;
                else {
                    grid[i][j] = DMAX;
                    if (i > 0) grid[i][j] = min(grid[i][j], grid[i - 1][j] + 1);
                    if (j > 0) grid[i][j] = min(grid[i][j], grid[i][j - 1] + 1);
                }

        int ans = 0;
        for (int i = n - 1; i > -1; --i)
            for (int j = n - 1; j > -1; --j) {
                if (i < n - 1) grid[i][j] = min(grid[i][j], grid[i + 1][j] + 1);
                if (j < n - 1) grid[i][j] = min(grid[i][j], grid[i][j + 1] + 1);
                ans = max(ans, grid[i][j]);
            }

        return (ans == 0 || ans == DMAX) ? -1 : ans;
    }

    int maxDistance_dfs(vector<vector<int>>& grid) {
        vector<vector<int>> dist(grid.size(), vector<int>(grid.size(), INT_MAX));
        int nland = 0;
        for (int i = 0; i < grid.size(); ++i)
            for (int j = 0; j < grid.size(); ++j)
                if (grid[i][j] == 1) {
                    ++nland;
                    flood(i, j, i, j, grid, dist);
                }

        if (nland == 0 || nland == grid.size() * grid.size())
            return -1;

        int res = INT_MIN;
        for (int i = 0; i < dist.size(); ++i)
            for (int j = 0; j < dist.size(); ++j)
                res = max(res, dist[i][j]);

        return res;  
        
    }
};
