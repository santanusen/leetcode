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
    vector<TreeNode*> allPossibleFBT(int n) {
        if (n % 2 == 0) return {};

        vector<vector<TreeNode*>> dp(n + 1);
        dp[1].push_back(new TreeNode(0));

        for (int i = 3; i <= n; i += 2) {
            for (int l = 1; l < i - 1; l += 2) {
                int r = i - 1 - l;
                for (TreeNode* lc : dp[l])
                    for (TreeNode* rc : dp[r])
                        dp[i].push_back(new TreeNode(0, lc, rc));
            }
        }
        return dp[n];
    }
};

auto _=[](){ios::sync_with_stdio(false); cin.tie(0); cout.tie(0); return 0;}();
