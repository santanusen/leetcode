class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int MAX = n * n + 1;
        vector<vector<int>> res(n, vector<int>(n, MAX));
        int i = 0, j = 0;
        int dd[][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int d = 0;
        for (int x = 1; x < MAX; ++x) {
            res[i][j] = x;
            if (i + dd[d][0] >= n || i + dd[d][0] < 0 ||
                j + dd[d][1] >= n || j + dd[d][1] < 0 ||
                res[i + dd[d][0]][j + dd[d][1]] != MAX)
                d = (d + 1) % 4;
            i += dd[d][0];
            j += dd[d][1];
        }

        return res;
    }
};
