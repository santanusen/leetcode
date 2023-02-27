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
/*class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root) {        
            swap(root->left, root->right);
            invertTree(root->left);
            invertTree(root->right);
        }
        return root;
    }
};*/
class Solution {
    void dfs(TreeNode* root) {
        swap(root->left, root->right);
        if (root->left) dfs(root->left);
        if (root->right) dfs(root->right);
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return NULL;
        dfs(root);
        return root;
    }
};
