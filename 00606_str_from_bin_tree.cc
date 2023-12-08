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
  void tree2str(TreeNode* root, string& ans) {
    if (!root) return;

    ans += to_string(root->val);
    if (root->left || root->right) {
      ans.push_back('(');
      tree2str(root->left, ans);
      ans.push_back(')');
    }

    if (root->right) {
      ans.push_back('(');
      tree2str(root->right, ans);
      ans.push_back(')');
    }
  }

public:

    string tree2str(TreeNode* root) {
      string ans;
      tree2str(root, ans);
      return ans;
    }

    string tree2str2(TreeNode* root) {
        string ans = to_string(root->val);
        if (root->left)
            ans += ("(" + tree2str(root->left) + ")");
        else if (root->right)
            ans += "()";

        if (root->right)
            ans += ("(" + tree2str(root->right) + ")");
        
        return ans;
    }
};

auto _ = [](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
