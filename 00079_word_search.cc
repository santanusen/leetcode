class Solution {
    
    bool dfs(vector<vector<char>>& board, int i, int j, string word, int s) {
        // Base cases
        if (s == word.size()) // Found
            return true;
        
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[s]) // No solution in this path
            return false;
        
        board[i][j] = '\0'; // Seen
        bool ret = 
            dfs(board, i + 1, j, word, s + 1) ||
            dfs(board, i, j + 1, word, s + 1) ||
            dfs(board, i - 1, j, word, s + 1) ||
            dfs(board, i, j - 1, word, s + 1);
        board[i][j] = word[s]; // Backtrack
        
        return ret;
            
        
    }
    
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); ++i)
            for(int j = 0; j < board[0].size(); ++j)
                if (dfs(board, i, j, word, 0))
                    return true;
        return false;
        
    }
};
