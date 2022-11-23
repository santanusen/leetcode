class Solution {
    
public:
    bool isValidSudoku2(vector<vector<char>>& board) {
      // Validate Rows
      for (int i = 0; i < board.size(); ++i) {
          int freq[10] = {0};
          for (int j = 0; j < board[0].size(); ++j)
              if (board[i][j] != '.' && ++freq[board[i][j] - '0'] > 1)
                      return false;
      }
        
      // Validate Cols
      for (int j = 0; j < board[0].size(); ++j) {
          int freq[10] = {0};
          for (int i = 0; i < board.size(); ++i)
              if (board[i][j] != '.' && ++freq[board[i][j] - '0'] > 1)
                      return false;
      }
        
      // Validate boxes
      for (int ii = 0; ii < board.size(); ii += 3)
          for (int jj = 0; jj < board[0].size(); jj += 3) {
              int freq[10] = {0};
              for (int i = 0; i < 3; ++i)
                  for (int j = 0; j < 3; ++j)
                      if (board[ii + i][jj + j] != '.' && ++freq[board[ii + i][jj + j] - '0'] > 1)
                          return false;
      }
           
      return true;
        
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        int rused[9][9] = {0}, cused[9][9] = {0}, bused[9][9] = {0};
        
        for (int i = 0; i < 9; ++i)
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.')
                    continue;
                int n = board[i][j] - '0' - 1;
                if (++rused[i][n] > 1) return false;
                if (++cused[j][n] > 1) return false;
                int k = 3 * (i / 3) + j / 3;
                if (++bused[k][n] > 1) return false;
            }
        
        return true;
    }
    
};
