auto _ = []() {ios::sync_with_stdio(false); cin.tie(0); cout.tie(0); return false;} ();

class Solution {

public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        uint8_t dstmask = 0;
        int si = -1, sj = -1;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (islower(grid[i][j]))
                    dstmask |= (1 << (grid[i][j] - 'a'));
                else if (grid[i][j] == '@') {
                    si = i;
                    sj = j;
                }
            }
        }

        //vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(dstmask + 1, false)));
        //vector<vector<uint64_t>> visited(m, vector<uint64_t>(n));
        uint64_t visited[m][n];
        memset(visited, 0, sizeof(uint64_t) * m * n);
        queue<tuple<int, int, uint8_t, int>> q; // x, y, keymask, distance
        q.push({si, sj, 0, 0});
        visited[si][sj] |= (1ULL);

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        while (!q.empty()) {
            auto[i, j, keys, l] = q.front(); q.pop();
            for (int d = 0; d < 4; ++d) {
                int ii = i + dx[d];
                int jj = j + dy[d];

                if (ii > -1 && ii < m && jj > -1 && jj < n &&
                    !(visited[ii][jj] & (1ULL << keys)) && grid[ii][jj] != '#') {
                    visited[ii][jj] |= (1ULL << keys);
                    auto gval = grid[ii][jj];
                    if (islower(gval)) { // Found a key
                        uint8_t nkeys = keys | (1 << (gval - 'a'));
                        if (nkeys != keys) {
                            if (nkeys == dstmask)
                                return l + 1;
                            visited[ii][jj] |= (1ULL << nkeys);
                            q.push({ii, jj, nkeys, l + 1});
                        }
                        q.push({ii, jj, keys, l + 1});
                    } else if (isupper(gval)) { // Hit a lock
                        if (keys & (1 << (gval - 'A'))) {
                            q.push({ii, jj, keys, l + 1});
                        }
                    } else {
                        q.push({ii, jj, keys, l + 1});
                    }
                }
            }
        }

        return -1;
    }
};



class Solution_dfs_of_bfs {
    int IMAX = 18000;

    int dfs(vector<string>& grid, int x, int y, uint8_t keys, uint8_t dstmask,
            vector<vector<vector<int>>>& memo) {
        if (keys >= dstmask) return 0;

        if (memo[x][y][keys] != -1)
            return memo[x][y][keys];

        int mmin = IMAX;

        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        queue<pair<int, int>> q;
        q.push({x, y});
        visited[x][y] = true;

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        int l = 1;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto[i, j] = q.front(); q.pop();
                for (int d = 0; d < 4; ++d) {
                    int ii = i + dx[d];
                    int jj = j + dy[d];

                    if (ii > -1 && ii < m && jj > -1 && jj < n && !visited[ii][jj] && grid[ii][jj] != '#') {
                        visited[ii][jj] = true;
                        auto gval = grid[ii][jj];
                        if (islower(gval)) { // Found a key
                            uint8_t nkeys = keys | (1 << (gval - 'a'));
                            if (nkeys != keys) {
                                mmin = min(mmin, l + dfs(grid, ii, jj, nkeys, dstmask, memo));
                            }
                            q.push({ii, jj});
                        } else if (isupper(gval)) { // Hit a lock
                            if (keys & (1 << (gval - 'A'))) {
                                q.push({ii, jj});
                            }
                        } else {
                            q.push({ii, jj});
                        }
                    }
                }
            }
            ++l;
        }

        return (memo[x][y][keys] = mmin);
    }

public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        uint8_t dstmask = 0;
        int si = -1, sj = -1;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (islower(grid[i][j]))
                    dstmask |= (1 << (grid[i][j] - 'a'));
                else if (grid[i][j] == '@') {
                    si = i;
                    sj = j;
                }
            }
        }

        vector<vector<vector<int>>> memo(m, vector<vector<int>>(n, vector<int>(dstmask + 1, -1)));
        int ans = dfs(grid, si, sj, 0, dstmask, memo);

        return (ans >= IMAX ? -1 : ans);
        
    }
};
