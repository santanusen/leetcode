auto _ = []() {ios::sync_with_stdio(false); cin.tie(0); cout.tie(0); return false;} ();

class DSU {
    vector<int> root, size;

public:

    DSU(int n)
    : root(n), size(n, 1) {
        for (int i = 0; i < n; ++i)
            root[i] = i;
    }

    int find(int x) {
        if (root[x] != x)
            root[x] = find(root[x]);
        return root[x];
    }

    bool join(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return false;

        if (size[px] > size[py])
            swap(px, py);
        root[px] = py;
        size[py] += size[px];

        return true;
    }

};


class Solution {


public:
    int latestDayToCross(const int row, const int col, vector<vector<int>>& cells) {
        const int N = row * col;
        DSU dsu(N + 2);
        const int dx[4] = {1, 0, 0, -1};
        const int dy[4] = {0, 1, -1, 0};

        vector<vector<bool>> grid(row, vector<bool>(col, false));

        for (int i = cells.size() - 1; i > -1; --i) {
            int r = cells[i][0] - 1;
            int c = cells[i][1] - 1;
            grid[r][c] = true;
            int irc = r * col + c + 1;

            for (int d = 0; d < 4; ++d) {
                int x = r + dx[d];
                int y = c + dy[d];
                int ixy = x * col + y + 1;
                if (x > -1 && x < row && y > -1 && y < col && grid[x][y]) {                 
                    dsu.join(irc, ixy);
                }
            }

            if (r == 0)
                dsu.join(0, irc);

            if (r == row - 1)
                dsu.join(N + 1, irc);

            if (dsu.find(0) == dsu.find(N + 1))
                return i;
        }

        return -1;
    }
};


class Solution_DFS {
    const int dx[4] = {1, 0, 0, -1};
    const int dy[4] = {0, 1, -1, 0};

    bool dfs(vector<vector<bool>>& grid, int i, int j) {
        int m = grid.size(), n = grid[0].size();
        if (i == m - 1) return true;

        grid[i][j] = true;

        for (int d = 0; d < 4; ++d) {
            int x = i + dx[d], y = j + dy[d];
            if (x > -1 && x < m && y > -1 && y < n && !grid[x][y]) {
                if (dfs(grid, x, y))
                    return true;
            }
        }
        return false;

    }

    bool can_walk(int row, int col, vector<vector<int>>& cells, int day) {
        vector<vector<bool>> grid(row, vector<bool>(col, false));
        for (int i = 0; i < day; ++i)
            grid[cells[i][0] - 1][cells[i][1] - 1] = true;

        for (int c = 0; c < col; ++c)
            if (!grid[0][c] && dfs(grid, 0, c))
                return true;

        return false;
    }


public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int l = min(row, col) - 1, r = cells.size() - 1;

        while (l <= r) {
            int m = r - (r - l) / 2;
            if (can_walk(row, col, cells, m))
                l = m + 1;
            else
                r = m - 1;
        }

        return r;         
    }
};

class Solution_BFS {
    bool can_walk(int row, int col, vector<vector<int>>& cells, int day) {
        if (day < min(row, col)) return true;

        vector<vector<bool>> grid(row, vector<bool>(col, false));
        for (int i = 0; i < day; ++i)
            grid[cells[i][0] - 1][cells[i][1] - 1] = true;

        int dx[] = {1, 0, 0, -1};
        int dy[] = {0, 1, -1, 0};

        queue<pair<int, int>> q;
        for (int c = 0; c < col; ++c) {
            if (!grid[0][c]) {
                grid[0][c] = true;
                q.push({0, c});
            }
        }

        while (!q.empty()) {
            auto [r, c] = q.front(); q.pop();
            if (r == row - 1)
                return true;

            for (int d = 0; d < 4; ++d) {
                int x = r + dx[d], y = c + dy[d];
                if (x > -1 && x < row && y > -1 && y < col && !grid[x][y]) {
                    grid[x][y] = true;
                    q.push({x, y});
                }
            }

        }

        return false;
    }


public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int l = min(row, col) - 1, r = cells.size() - 1;

        while (l <= r) {
            int m = r - (r - l) / 2;
            if (can_walk(row, col, cells, m))
                l = m + 1;
            else
                r = m - 1;
        }

        return r;         
    }
};
