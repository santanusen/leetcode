/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    bool stop;
    
    // Subtract number of missing children at level pl
    // from right to left. Stop if a complete node is found at
    // level pl.
    void subMissingNodes(TreeNode* root, int pl, int l, int& n) {
        if (!root || stop)
            return;
        
        if (l == pl) {
            int c = 0;
            if (!root->left)
                c += 2;
            else if (!root->right)
                c += 1;
            n -= c;
            if (!c) stop = true;
            
            return;
        }
        
        subMissingNodes(root->right, pl, l + 1, n);
        subMissingNodes(root->left, pl, l + 1, n);      
    }
    
public:
    int countNodes(TreeNode* root) {
        if (!root)
            return 0;
       
        // Count nodes of complete binary tree.
        int l = 0, n = 0, ln = 1; // level, number of nodes, nodes at level;
        for (auto cur = root; cur; cur = cur->left, ++l, ln <<= 1)
            n += ln;
        
        if (n < 2) // Singleton
            return n;
        
        // Subtract missing nodes from n.
        stop = false;
        subMissingNodes(root, l - 2, 0, n);
        return n;
    }
};
