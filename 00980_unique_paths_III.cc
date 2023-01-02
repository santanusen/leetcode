class Solution {
    int DFS (vector<vector<int>>& grid, int vc, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == -1)
            return 0;

        if (grid[i][j] == 2)
            return ((vc + 1 == grid.size() * grid[0].size()) ? 1 : 0);

        grid[i][j] = -1;
        int n = DFS(grid, vc + 1, i + 1, j) +
                DFS(grid, vc + 1, i - 1, j) +
                DFS(grid, vc + 1, i, j + 1) +
                DFS(grid, vc + 1, i, j - 1);

        grid[i][j] = 0;
        return n;
    }

public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int vc = 0, si = -1, sj = -1;
        for (int i = 0; i < grid.size(); ++i)
            for (int j = 0; j < grid[0].size(); ++j) {
                vc += (grid[i][j] == -1);
                if (grid[i][j] == 1) {
                    si = i;
                    sj = j;
                }
            }

        return DFS(grid, vc, si, sj);
    }
};

