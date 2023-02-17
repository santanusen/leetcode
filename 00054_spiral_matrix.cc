class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        const int R = matrix.size(), C = matrix[0].size(), VISITED = 500;
        int i = 0, j = 0;
        vector<vector<int>> dir {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int d = 0;

        while (res.size() < R * C) {
            res.push_back(matrix[i][j]);
            matrix[i][j] = VISITED;
            if (i + dir[d][0] >= R || i + dir[d][0] < 0 ||
                j + dir[d][1] >= C || j + dir[d][1] < 0 ||
                matrix[i + dir[d][0]][j + dir[d][1]] == VISITED)
                d = (d + 1) % 4;
            i += dir[d][0];
            j += dir[d][1];
        }

        return res;
        
    }
}
