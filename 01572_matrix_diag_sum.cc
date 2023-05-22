static const int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size(), ans = 0;
        for (int i = 0; i < n; ++i)
            ans += (mat[i][i] + mat[i][n - 1 - i]);
            
        if (n & 0x1)
            ans -= mat[n >> 1][n >> 1];
        return ans;
    }
};
