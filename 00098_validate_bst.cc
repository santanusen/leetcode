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
    bool isValidBST2(TreeNode* cur, TreeNode* nmin, TreeNode* nmax) {
        if (!cur) return true;
        if (nmin && cur->val <= nmin->val) return false;
        if (nmax && cur->val >= nmax->val) return false;

        return isValidBST2(cur->left, nmin, cur) &&
               isValidBST2(cur->right, cur, nmax);
    }

    bool isValidBST(TreeNode* cur, long long nmin, long long nmax) {
        if (!cur) return true;
        long long cval = cur->val;
        if (cval <= nmin || cval >= nmax) return false;

        return isValidBST(cur->left, nmin, cval) &&
               isValidBST(cur->right, cval, nmax);
    }
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LLONG_MIN, LLONG_MAX);
    }
};
