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
public:
    
    int isBalRec(TreeNode* root) {
        if (!root) return 0;
        
        int dl = isBalRec(root->left);
        if (dl < 0) return -1;
        int dr = isBalRec(root->right);
        if (dr < 0) return -1;
        
        return (abs(dl - dr) < 2) ? 1 + max(dl, dr) : -1;
    }
    
    bool isBalanced(TreeNode* root) {
        return isBalRec(root) >= 0;
    }
};

class Solution2 {
public:
    
    bool isBalanced(TreeNode* root, int& depth) {
        if (!root) {
            depth = 0;
            return true;
        }
        
        int dl, dr;
        if (!isBalanced(root->left, dl) || !isBalanced(root->right, dr))
            return false;
        depth = 1 + max(dl, dr);
        return abs(dl - dr) < 2;
    }
    bool isBalanced(TreeNode* root) {
        int d;
        return isBalanced(root, d);
    }
};
