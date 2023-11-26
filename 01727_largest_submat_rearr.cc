class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();


        for (int r = 1; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (matrix[r][c])
                    matrix[r][c] += matrix[r - 1][c];
            }
        }

        int ans = 0;
        for (auto& row : matrix) {
            sort(row.begin(), row.end(), greater());
            for (int i = 0; i < n; ++i)
                ans = max(ans, row[i] * (i + 1));
        }

        return ans;
        
    }
};

auto _ = [](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
