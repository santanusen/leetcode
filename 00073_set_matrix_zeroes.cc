class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        bool r0 = false, c0 = false;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (matrix[i][j] == 0) {
                    matrix[i][0] = matrix[0][j] = 0;
                    if (i == 0) r0 = true;
                    if (j == 0) c0 = true;
                }

        for (int r = 1; r < m; ++r)
            if (matrix[r][0] == 0)
                for (int c = 1; c < n; ++c)
                    matrix[r][c] = 0;

        for (int c = 1; c < n; ++c)
            if (matrix[0][c] == 0)
                for (int r = 1; r < m; ++r)
                    matrix[r][c] = 0;

        if (matrix[0][0] == 0) {
            if (c0)
                for (int r = 1; r < m; ++r)
                    matrix[r][0] = 0;
            if (r0)
                for (int c = 1; c < n; ++c)
                    matrix[0][c] = 0;
        }
    }

    void setZeroes1(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        unordered_set<int> rows, cols;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (matrix[i][j] == 0) {
                    rows.insert(i);
                    cols.insert(j);
                }

        for (auto r : rows)
            for (int c = 0; c < n; ++c)
                matrix[r][c] = 0;

        for (auto c : cols)
            for (int r = 0; r < m; ++r)
                matrix[r][c] = 0;
    }

    void setZeroes2(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<bool> rows(m), cols(n);
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (matrix[i][j] == 0)
                    rows[i] = cols[j] = true;

        /*
        for (int r = 0; r < m; ++r)
            if (rows[r])
                for (int c = 0; c < n; ++c)
                    matrix[r][c] = 0;

        for (int c = 0; c < n; ++c)
            if (cols[c])
                for (int r = 0; r < m; ++r)
                    matrix[r][c] = 0;
        */

        for (int r = 0; r < m; ++r)
            for (int c = 0; c < n; ++c)
                if (rows[r] || cols[c])
                    matrix[r][c] = 0;

    }
};
