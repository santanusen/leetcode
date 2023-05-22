class Solution {
    void dfsIsl(vector<vector<int>>& grid, int i, int j, queue<pair<int, int>>& q) {
        grid[i][j] = 2;
        q.push({i, j});

        int dx[] = {+1, -1, 0, 0};
        int dy[] = {0, 0, +1, -1};

        for (int d = 0; d < 4; ++d) {
            int x = i + dx[d], y = j + dy[d];
            if (x > -1 && x < grid.size() && y > -1 && y < grid[0].size() && grid[x][y] == 1)
                dfsIsl(grid, x, y, q);
        }
    }

    int bfs(vector<vector<int>>& grid, queue<pair<int, int>>& q) {
        int level = 0;

        int dx[] = {+1, -1, 0, 0};
        int dy[] = {0, 0, +1, -1};

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto cur = q.front(); q.pop();

                for (int d = 0; d < 4; ++d) {
                    int x = cur.first + dx[d], y = cur.second + dy[d];
                    if (x > -1 && x < grid.size() && y > -1 && y < grid[0].size()) {
                        if (grid[x][y] == 1) return level;    
                        if (grid[x][y] == 0) {
                            grid[x][y] = -1;
                            q.push({x, y});
                        }
                    }
                }
            }
            ++level;
        }

        return INT_MAX;
    }

public:
    int shortestBridge(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    queue<pair<int, int>> q;
                    dfsIsl(grid, i, j, q);
                    return bfs(grid, q);
                }
            }
        }

        return 0;
        
    }
};

class Solution1 {
    int w = 0;

    void dfsIsl(vector<vector<int>>& grid, int i, int j) {
        grid[i][j] = 2;

        int dx[] = {+1, -1, 0, 0};
        int dy[] = {0, 0, +1, -1};

        for (int d = 0; d < 4; ++d) {
            int x = i + dx[d], y = j + dy[d];
            if (x > -1 && x < grid.size() && y > -1 && y < grid[0].size() && grid[x][y] == 1)
                dfsIsl(grid, x, y);
        }
    }

    int bfs(vector<vector<int>>& grid, int i, int j) {
        queue<pair<int, int>> q;
        q.push({i, j});

        --w;
        int level = 0;

        int dx[] = {+1, -1, 0, 0};
        int dy[] = {0, 0, +1, -1};

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto cur = q.front(); q.pop();

                for (int d = 0; d < 4; ++d) {
                    int x = cur.first + dx[d], y = cur.second + dy[d];
                    if (x > -1 && x < grid.size() && y > -1 && y < grid[0].size()) {
                        if (grid[x][y] == 2) return level;    
                        if (grid[x][y] < 1 && grid[x][y] > w) {
                            grid[x][y] = w;
                            q.push({x, y});
                        }
                    }
                }
            }
            ++level;
        }

        return INT_MAX;
    }

    int dfsDist(vector<vector<int>>& grid, int i, int j) {
        grid[i][j] = 3;
        int dmin = bfs(grid, i, j);

        int dx[] = {+1, -1, 0, 0};
        int dy[] = {0, 0, +1, -1};

        for (int d = 0; d < 4; ++d) {
            int x = i + dx[d], y = j + dy[d];
            if (x > -1 && x < grid.size() && y > -1 && y < grid[0].size() && grid[x][y] == 1)
                dmin = min(dmin, dfsDist(grid, x, y));
        }

        return dmin;
    }

public:
    int shortestBridge(vector<vector<int>>& grid) {
        bool isl1 = false;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    if (!isl1) {
                        isl1 = true;
                        dfsIsl(grid, i, j);
                    } else
                        return dfsDist(grid, i, j);
                }
            }
        }

        return 0;
        
    }
};

class Solution2 {
    void dfsIsl(vector<vector<int>>& grid, int i, int j, vector<pair<int, int>>& isl) {
        grid[i][j] = 2;
        isl.push_back({i, j});

        int dx[] = {+1, -1, 0, 0};
        int dy[] = {0, 0, +1, -1};

        for (int d = 0; d < 4; ++d) {
            int x = i + dx[d], y = j + dy[d];
            if (x > -1 && x < grid.size() && y > -1 && y < grid[0].size() && grid[x][y] == 1)
                dfsIsl(grid, x, y, isl);
        }
    }

    int dfsDist(vector<vector<int>>& grid, int i, int j, vector<pair<int, int>>& isl) {
        grid[i][j] = 3;
        int dmin = INT_MAX;
        for (auto& [x, y] : isl) {
            dmin = min(dmin, abs(x - i) + abs(y - j) - 1);
        }

        int dx[] = {+1, -1, 0, 0};
        int dy[] = {0, 0, +1, -1};

        for (int d = 0; d < 4; ++d) {
            int x = i + dx[d], y = j + dy[d];
            if (x > -1 && x < grid.size() && y > -1 && y < grid[0].size() && grid[x][y] == 1)
                dmin = min(dmin, dfsDist(grid, x, y, isl));
        }

        return dmin;
    }

public:
    int shortestBridge(vector<vector<int>>& grid) {
        vector<pair<int, int>> isl1;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    if (isl1.empty())
                        dfsIsl(grid, i, j, isl1);
                    else
                        return dfsDist(grid, i, j, isl1);
                }
            }
        }

        return 0;
        
    }
};
