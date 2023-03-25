class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        // all elements on same diagonal have same i-j result.
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> map; // min priority queue
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                map[i - j].push(mat[i][j]);
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                mat[i][j] = map[i - j].top(); map[i - j].pop();
            }
        }
        return mat;
    }

    vector<vector<int>> diagonalSort2(vector<vector<int>>& mat) {
        int ds = min(mat.size(), mat[0].size());
        if (ds < 2) return mat;

        vector<int> diag(ds);

        for (int r = 0; r < mat.size(); ++r) {
            int d = 0;
            for (int c = 0; r + c < mat.size() && c < mat[0].size(); ++c)
                diag[d++] = mat[r + c][c];

            sort(diag.begin(), diag.begin() + d);

            d = 0;
            for (int c = 0; r + c < mat.size() && c < mat[0].size(); ++c)
                mat[r + c][c] = diag[d++];            
        }

        for (int c = 1; c < mat[0].size(); ++c) {
            int d = 0;
            for (int r = 0; c + r < mat[0].size() && r < mat.size(); ++r)
                diag[d++] = mat[r][c + r];

            sort(diag.begin(), diag.begin() + d);

            d = 0;
            for (int r = 0; c + r < mat[0].size() && r < mat.size(); ++r)
                mat[r][c + r] = diag[d++];            
        }

        return mat;
        
    }
};
