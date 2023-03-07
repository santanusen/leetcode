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
    
    string dfs(TreeNode* cur, unordered_map<string, int>& htable, vector<TreeNode*>& res) {
        if (!cur) return "";
        string stree = to_string(static_cast<short>(cur->val)) + "L" +
                        dfs(cur->left, htable, res) + "R" + dfs(cur->right, htable, res);
        if (++htable[stree] == 2)
            res.push_back(cur);
        return stree;
    }

public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> res;
        unordered_map<string, int> htable;
        dfs(root, htable, res);
        return res;    
    }
};
