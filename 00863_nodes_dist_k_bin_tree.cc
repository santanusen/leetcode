/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    bool record_route(TreeNode* root, int tval, vector<TreeNode*>& route) {
        if (!root)
            return false;

        route.push_back(root);
        if (root->val == tval)
            return true;
        if (record_route(root->left, tval, route))
            return true;
        if (record_route(root->right, tval, route))
            return true;
        route.pop_back();
        return false;
    }

    void bfs(TreeNode* root, int k, TreeNode* excl, vector<int>& ans) {
        queue<TreeNode*> q;
        q.push(root);

        int l = 0;
        while (!q.empty() && l < k) {
            int sz = q.size();
            while (sz--) {
                auto cur = q.front(); q.pop();
                if (cur->left && cur->left != excl) q.push(cur->left);
                if (cur->right && cur->right != excl) q.push(cur->right);
            }
            ++l;
        }

        while (!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;

        vector<TreeNode*> route;
        record_route(root, target->val, route);

        int n = route.size();
        int imax = min((n - 1), k);
        TreeNode* excl = NULL;
        for (int i = 0; i <= imax; ++i) {
            auto cur = route[n - 1 - i];
            bfs(cur, k - i, excl, ans);
            excl = cur;
        }

        return ans;
    }
};

auto _ = [](){ios::sync_with_stdio(false); cin.tie(0); cout.tie(0); return false;}();
