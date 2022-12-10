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
    int maxAncestorDiff(TreeNode* cur, int mn, int mx) {
        if (!cur) return mx - mn;
        mx = max(mx, cur->val);
        mn = min(mn, cur->val);
        return max(maxAncestorDiff(cur->left, mn, mx),
                   maxAncestorDiff(cur->right, mn, mx));
    }

public:
    int maxAncestorDiff(TreeNode* root) {
        return maxAncestorDiff(root, INT_MAX, INT_MIN);
    }
};
