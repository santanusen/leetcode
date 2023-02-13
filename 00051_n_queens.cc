class Solution {
    bool can_place(int row, int col, vector<int>& placed) {
        for (int c = 0; c < col; ++c) {
            if (placed[c] == row)
                return false;
            if (abs(col - c) == abs(row - placed[c]))
                return false;
        }
        return true;
    }

    void dfs(int col, int N, vector<int>& placed, vector<vector<string>>& res) {
        if (col == N) {
            res.push_back({});
            
            for (auto r : placed) {
                string s(N, '.');
                s[r] = 'Q';
                res.back().push_back(s);
            }
            return;
        }

        for (int row = 0; row < N; ++row) {
            if (can_place(row, col, placed)) {
                placed[col] = row;
                dfs(col + 1, N, placed, res);
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<int> placed(n);
        dfs(0, n, placed, res);
        return res;
    }
};
