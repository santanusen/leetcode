class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        if (matrix.size() == 1) return matrix[0][0];

        int row_min = INT_MAX;
        for (int i = matrix.size() - 2; i > -1; --i) {
            row_min = INT_MAX;
            for (int j = 0; j < matrix.size(); ++j) {
                int min_nbr = matrix[i + 1][j];
                if (j > 0) min_nbr = min(min_nbr, matrix[i + 1][j - 1]);
                if (j + 1 < matrix.size()) min_nbr = min(min_nbr, matrix[i + 1][j + 1]);
                matrix[i][j] += min_nbr;
                row_min = min(row_min, matrix[i][j]);
            }
        }

        return row_min;
        
    }
};
