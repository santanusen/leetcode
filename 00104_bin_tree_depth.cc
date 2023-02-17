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
    int maxDepth_dfs(TreeNode* root) {
        if (!root) return 0;
        stack<pair<TreeNode*, int>> s;
        int l = 0;
        s.push({root, 1});
        while (!s.empty()) {
            auto p = s.top(); s.pop();
            l = max(l, p.second);
            if (p.first->left) s.push({p.first->left, p.second + 1});
            if (p.first->right) s.push({p.first->right, p.second + 1});
        }

        return l;
    }

    int maxDepth_bfs(TreeNode* root) {
        if (!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int l = 0;
        while (!q.empty()) {
            ++l;
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                root = q.front(); q.pop();
                if (root->left) q.push(root->left);
                if (root->right) q.push(root->right);
            }
        }
        return l;
    }

    int maxDepth(TreeNode* root) {   
        return (root) ? 1 + max(maxDepth(root->left), maxDepth(root->right)) : 0;
    }
};
