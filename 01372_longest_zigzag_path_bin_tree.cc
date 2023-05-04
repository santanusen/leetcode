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
    int ans = 0;
    pair<int, int> dfs(TreeNode* root) {
        if (!root) return {-1, -1};
        pair<int, int> zag {dfs(root->left).second + 1, dfs(root->right).first + 1};
        ans = max({ans, zag.first, zag.second});
        return zag;
    }
public:
    int longestZigZag(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
