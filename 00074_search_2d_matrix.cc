class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rl = 0, rr = matrix.size() - 1;
        while (rl <= rr) {
            int rm = (rl + rr) / 2;
            int x = matrix[rm][0];
            if (x == target) return true;
            if (x < target) rl = rm + 1;
            else rr = rm - 1;
        }
        if (rr < 0) return false;

        int cl = 0, cr = matrix[0].size() - 1;
        while (cl <= cr) {
            int cm = (cl + cr) / 2;
            int x = matrix[rr][cm];
            if (x == target) return true;
            if (x < target) cl = cm + 1;
            else cr = cm - 1;
        }

        return false;
        
    }
};
