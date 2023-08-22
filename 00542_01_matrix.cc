class Solution {
public:
    vector<vector<int>> updateMatrix_bfs(vector<vector<int>>& mat) {
        queue<pair<int, int>> q;
        int m = mat.size(), n = mat[0].size();

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (mat[i][j] == 0)
                    q.push({i, j});
                else
                    mat[i][j] = INT_MAX;

        int dx[] = {+1, -1,  0,  0};
        int dy[] = { 0,  0, +1, -1};

        while (!q.empty()) {
            auto [i, j] = q.front(); q.pop();
            for (int d = 0; d < 4; ++d) {
                int x = i + dx[d], y = j + dy[d];
                if (x > -1 && x < m && y > -1 && y < n && mat[i][j] + 1 < mat[x][y]) {
                    mat[x][y] = mat[i][j] + 1;
                    q.push({x, y});
                }
            }
        }

        return mat;
        
    }

    vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
        int m = mat.size(), n = mat[0].size(), INF = m + n;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (mat[r][c] == 0) continue;
                int top = (r - 1 > -1 ? mat[r - 1][c] : INF);
                int left =  (c - 1 > -1 ? mat[r][c - 1] : INF);
                mat[r][c] = min(top, left) + 1;
            }
        }
        for (int r = m - 1; r > -1; --r) {
            for (int c = n - 1; c > -1; --c) {
                if (mat[r][c] == 0) continue;
                int bottom = (r + 1 < m ? mat[r + 1][c] : INF);
                int right = (c + 1 < n ? mat[r][c + 1] : INF);
                mat[r][c] = min(mat[r][c], min(bottom, right) + 1);
            }
        }
        return mat;
    }
};

auto _ = [](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
