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
    int widthOfBinaryTree(TreeNode* root) {
        long long int ans = 0;
        queue<pair<TreeNode*, long long int>> q;
        q.push({root, 0});
        while (!q.empty()) {
            auto offset = q.front().second;
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                auto [cur, idx] = q.front(); q.pop();
                if (i + 1 == sz)
                    ans = max(ans, idx - offset + 1);
                if (cur->left)
                    q.push({cur->left, (idx - offset) << 1});
                if (cur->right)
                    q.push({cur->right, ((idx - offset) << 1) + 1});
            }
        }
        return ans;
    }
};
