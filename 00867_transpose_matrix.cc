class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>> ans = vector(matrix[0].size(), vector<int>(matrix.size()));
        for (int i = 0; i < matrix.size(); ++i)
            for (int j = 0; j < matrix[0].size(); ++j)
                ans[j][i] = matrix[i][j];
        return ans;
    }
};

auto _ = [](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
