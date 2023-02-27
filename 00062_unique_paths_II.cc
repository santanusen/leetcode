class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        if (grid[0][0] == 1) return 0;

        for (int i = 1, v = 1; i < grid.size(); ++i) {
            if (grid[i][0] == 1) v = 0;
            grid[i][0] = v;
        }

        for (int j = 0, v = 1; j < grid[0].size(); ++j) {
            if (grid[0][j] == 1) v = 0;
            grid[0][j] = v;
        }

        for (int i = 1; i < grid.size(); ++i)
            for (int j = 1; j < grid[0].size(); ++j)
                grid[i][j] = (grid[i][j] == 1) ? 0 : grid[i - 1][j] + grid[i][j - 1];

        return grid[grid.size() - 1][grid[0].size() - 1];
        
    }
};
