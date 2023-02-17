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
    int res;
    TreeNode* prev;
    void inTrav(TreeNode* cur) {
        if (cur->left) inTrav(cur->left);
        if (prev) res = min(res, cur->val - prev->val);
        prev = cur;
        if (cur->right) inTrav(cur->right);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        int mdiff = INT_MAX;
        TreeNode *prev = NULL, *cur = root;
        stack<TreeNode*> s;
        while (cur || !s.empty()) {
            while (cur) {
                s.push(cur);
                cur = cur->left;
            }
            cur = s.top(); s.pop();
            if (prev) {
                mdiff = min(mdiff, cur->val - prev->val);
                if (mdiff == 0) return 0;
            }
            prev = cur;
            cur = cur->right;
        }
        return mdiff;
    }

    int gmd(TreeNode* root) {
        res = INT_MAX;
        prev = NULL;
        inTrav(root);
        return res;
    }
};
