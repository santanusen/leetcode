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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        int l = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            vector<int> v(sz);
            while (sz--) {
                root = q.front(); q.pop();
                v[(l % 2) ? sz : v.size() - 1 - sz] = root->val;
                if (root->left) q.push(root->left);
                if (root->right) q.push(root->right);
            }
            ++l;
            res.push_back(v);
        }

        return res;
        
    }
};
