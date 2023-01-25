class Solution {
    void findNextBlank(vector<vector<char>>& board, int& x, int& y) {
        for (; x < board.size(); ++x) {
            for (; y < board[0].size(); ++y)
                if (board[x][y] == '.')
                    return;
            y = 0;
        }
    }

    bool dfs(vector<vector<char>>& board, int x, int y) {
        if (x >= board.size()) return true; // No more blanks left.
        
        // Determine available numbers
        vector<bool> seen(9, false); 
        char n;
        // Remove numbers present in same row.
        for (int cc = 0; cc < board[0].size(); ++cc)
            if ((n = board[x][cc]) != '.')
                seen[n - '1'] = true;
        // Remove numbers present in same col.
        for (int rr = 0; rr < board.size(); ++rr)
            if ((n = board[rr][y]) != '.')
                seen[n - '1'] = true;
        // remove numbers present in same sub-box.
        for (int rs = x / 3 * 3, rr = 0; rr < 3; ++rr)
            for (int cs = y / 3 * 3, cc = 0; cc < 3; ++cc)
                if ((n = board[rs + rr][cs + cc]) != '.')
                    seen[n - '1'] = true;

        // Next row and col for dfs.
        int rn = x, cn = y + 1;
        if (cn == board[0].size()) {
            cn = 0;
            ++rn;
        }
        findNextBlank(board, rn, cn);
        // Recurse.
        for (int i = 0; i < 9; ++i) {
            if (!seen[i]) {
                board[x][y] = '1' + i;
                if (dfs(board, rn, cn))
                    return true;
            }
        }
        // Backtrack
        board[x][y] = '.';
        return false;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        int r = 0, c = 0;
        findNextBlank(board, r, c);
        dfs(board, r, c);
    }
};
