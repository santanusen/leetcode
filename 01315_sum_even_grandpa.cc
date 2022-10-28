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
    int recSumEvenGp(TreeNode* cur, int par, int gpr) {
        if (!cur) return 0;
        return ((cur->left) ? recSumEvenGp(cur->left, cur->val, par) : 0) +
            ((cur->right) ? recSumEvenGp(cur->right, cur->val, par) : 0) +
            ((gpr % 2 == 0) ? cur->val : 0);
    }
public:
    int sumEvenGrandparent(TreeNode* root) {
        return recSumEvenGp(root, 1, 1);       
    }
};
