/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
    bool same_val(vector<vector<int>>& grid, int n, int r, int c) {
        int v = grid[r][c];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[r + i][c + j] != v)
                    return false;
        return true;

    }

    Node* grid_recurse(vector<vector<int>>& grid, int n, int r, int c) {
        if (n == 1 || same_val(grid, n, r, c))
            return new Node(grid[r][c], true);

        n /= 2;
        return new Node(grid[r][c], false,
                        grid_recurse(grid, n, r, c),
                        grid_recurse(grid, n, r, c + n),
                        grid_recurse(grid, n, r + n, c),
                        grid_recurse(grid, n, r + n, c + n));
    }
public:
    Node* construct(vector<vector<int>>& grid) {
        return grid_recurse(grid, grid.size(), 0, 0);
    }
};
