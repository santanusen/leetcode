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
    TreeNode* prevNode;
    
    void b2gRec(TreeNode* root) {
        if (!root)
            return;
        if (root->right)
            b2gRec(root->right);
        
        if (prevNode)
            root->val += prevNode->val;
        prevNode = root;
        
        if (root->left)
            b2gRec(root->left);
    }
    
public:
    TreeNode* bstToGst(TreeNode* root) {
        prevNode = NULL;
        b2gRec(root);
        return root;
        
    }
};
