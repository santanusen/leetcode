class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        const int m = grid.size(), n = grid[0].size(), M = 1e5;
        //vector<int> rones(m), cones(n);
        int rones[M] = {0}, cones[M] = {0};
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) {
                    rones[i] += 2;
                    cones[j] += 2;
                }
            }

        int k = m + n;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                //int ones = rones[i] + cones[j];   
                //int zeroes = k - ones;
                //grid[i][j] = ones - zeroes;
                
                grid[i][j] = rones[i] + cones[j] - k;
            }
        
        return grid;
        
    }
};

auto _ = [](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
