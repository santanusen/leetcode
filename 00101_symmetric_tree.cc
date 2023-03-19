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
    bool isMirror(TreeNode* l, TreeNode* r) {
        if (!l && !r)
            return true;
        if (!l || !r)
            return false;
        if (l->val != r->val)
            return false;
        return isMirror(l->left, r->right) && isMirror(l->right, r->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        return isMirror(root->left, root->right);      
    }
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        while (!q.empty()) {
            auto l = q.front(); q.pop();
            auto r = q.front(); q.pop();
            if (l && r) {
                if (l->val != r->val) return false;

                q.push(l->left);
                q.push(r->right);

                q.push(l->right);
                q.push(r->left);
            } else {
                if (l || r) return false;
            }
        }

        return true;
    }
};
