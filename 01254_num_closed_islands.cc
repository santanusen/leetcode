class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int ans = 0, m = grid.size(), n = grid[0].size();
        int xd[] = {1, -1, 0, 0};
        int yd[] = {0, 0, 1, -1};
        for (int i = 1; i < m - 1; ++i) {
            for (int j = 1; j < n - 1; ++j) {
                if (grid[i][j] == 0) {
                    bool isClosed = true;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    while (!q.empty()) {
                        auto [x, y] = q.front(); q.pop();
                        if (x < 0 || y < 0 || x >= m || y >= n) {
                            isClosed = false;
                        } else if (grid[x][y] == 0) {
                            grid[x][y] = 2;
                            for (int d = 0; d < 4; ++d)
                                q.push({x + xd[d], y + yd[d]});
                        }
                    }
                    if (isClosed) ++ans;
                }
            }
        }

        return ans;
    }
};
