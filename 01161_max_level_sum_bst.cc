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
 auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(NULL); return 0; } ();
 
class Solution {
    void dfs(TreeNode* cur, int l, vector<int>& lsum) {
        if (lsum.size() < l + 1)
            lsum.push_back(cur->val);
        else
            lsum[l] += cur->val;
        if (cur->left) dfs(cur->left, l + 1, lsum);
        if (cur->right) dfs(cur->right, l + 1, lsum);
    }

public:
    int maxLevelSum(TreeNode* root) {
        vector<int> lsum;
        dfs(root, 0, lsum);
        return distance(lsum.begin(), max_element(lsum.begin(), lsum.end())) + 1;
    }

    int maxLevelSum_bfs(TreeNode* root) {
        int smax = root->val;
        int lmin = 1, level = 1;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int sz = q.size();
            int lsum = 0;
            while (sz--) {
                auto cur = q.front(); q.pop();
                lsum += cur->val;
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            if (lsum > smax) {
                lmin = level;
                smax = lsum;
            }
            ++level;
        }

        return lmin;
        
    }
};
