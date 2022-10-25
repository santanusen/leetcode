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
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        
        queue<TreeNode*> q;
        int l = 1;
        q.push(root);
        while(!q.empty()) {
            int nsib = q.size();
            for(int i = 0; i < nsib; ++i) {
                root = q.front(); q.pop();
                if (!root->left && !root->right)
                    return l;
                if (root->left) q.push(root->left);
                if (root->right) q.push(root->right);
            }
            ++l;
        }
        
        return l;
        
    }
};
