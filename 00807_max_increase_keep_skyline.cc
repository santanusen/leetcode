class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        // Find maximum height of each row and column
        vector<int> rmax (grid.size(), 0);
        vector<int> cmax (grid.size(), 0);
        for (int r = 0; r < grid.size(); ++r) {
            for (int c = 0; c < grid.size(); ++c) {
                rmax[r] = max(rmax[r], grid[r][c]);
                cmax[c] = max(cmax[c], grid[r][c]);
            }
        }
        
        // A building's height can be increased to the minimum
        // of maximum height of its row and column. 
        int sum = 0;
        for (int r = 0; r < grid.size(); ++r)
            for (int c = 0; c < grid.size(); ++c)
                sum += (min(rmax[r], cmax[c]) - grid[r][c]);
        
        return sum;     
    }
};
