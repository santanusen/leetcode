static const int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        for (int i = m - 1, j = 0; i > -1 && j < n; --i) {
            while (j < n && grid[i][j] > -1) ++j;
            ans += (n - j);
        }     
        return ans;
    }
};
