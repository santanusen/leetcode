class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size() - 1;
        int n = matrix[0].size() - 1;
        
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (matrix[i][j] != matrix[i + 1][j + 1])
                    return false;
                    
        return true;
        }
};
