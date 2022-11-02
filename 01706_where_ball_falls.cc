class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        
        int m = grid.size(), n = grid[0].size();
        
        vector<int> res(n, 0);
        for (int b = 0; b < n; ++b) {
            int c = b;
            for (int r = 0; r < m; ++r) {
                int cn = c + grid[r][c];
                if (cn < 0 || cn > n - 1 || grid[r][c] != grid[r][cn]) {
                    res[b] = -1;
                    break;
                }
                c = cn;
                res[b] = c;
            }
        }
        
        return res;
        
    }
};

