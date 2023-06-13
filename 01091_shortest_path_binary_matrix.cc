static const int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] || grid[n - 1][n - 1]) return -1;
        if (n == 1) return 1;

        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 2;
        int dy[] = {-1,  0,  1, -1,  1, -1,  0,  1};
        int dx[] = {-1, -1, -1,  0,  0,  1,  1,  1};

        int l = 1;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto[i, j] = q.front(); q.pop();

                for (int d = 0; d < 8; ++d) {
                    int x = i + dx[d], y = j + dy[d];
                    if (x == n - 1 && y == n - 1) return l + 1;
                    if (x > -1 && x < n && y > -1 && y < n && grid[x][y] == 0) {
                        grid[x][y] = 2;
                        q.push({x, y});
                    }
                }
            }
            ++l;
        }


        return -1;
        
    }
};
