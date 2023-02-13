class Solution {

    bool can_place(int row, int col, int* placed) {
        for (int c = 0; c < col; ++c) {
            if (placed[c] == row) return false;
            if (abs(col - c) == abs(row - placed[c])) return false;
        }
        return true;
    }

    int dfs(int col, int N, int* placed) {
        if (col == N)
            return 1;

        int res = 0;
        for (int row = 0; row < N; ++row) {
            if (can_place(row, col, placed)) {
                placed[col] = row;
                res += dfs(col + 1, N, placed);
            }
        }
        return res;
    }
public:
    int totalNQueens(int n) {
        int placed[n];
        return dfs(0, n, placed);
    }
};
