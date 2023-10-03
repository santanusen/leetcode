class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> cost(m, vector(n, INT_MAX));
        /*
        int cost[m][n];
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                cost[i][j] = INT_MAX;
        */
        cost[0][0] = 0;

        priority_queue<tuple<int, int, int>,
                       vector<tuple<int, int, int>>,
                       greater<tuple<int, int, int>>> pq;
        pq.push({0, 0, 0});

        int dy[] = {1, -1, 0, 0};
        int dx[] = {0, 0, 1, -1};

        while (!pq.empty()) {
            auto [c, x, y] = pq.top();
            pq.pop();

            if (x == m - 1 && y == n - 1)
                return c;

            for (int d = 0; d < 4; ++d) {
                int xx = x + dx[d], yy = y + dy[d];
                if (xx > -1 && xx < m && yy > -1 && yy < n) {
                    int cc = max(c, abs(heights[x][y] - heights[xx][yy]));
                    if (cc < cost[xx][yy]) {
                        cost[xx][yy] = cc;
                        pq.push({cc, xx, yy});
                    }
                }
            }
 
        }

        return INT_MAX;     
    }
};

auto _ = [](){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();
