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
    vector<int> postorderTraversal(TreeNode* root) {
        
        stack<TreeNode*> s;
        TreeNode *cur = root, *prev = NULL;
        vector<int> res;
        
        while (!s.empty() || cur) {
            while (cur) {
                s.push(cur);
                cur = cur->left;
            }
            
            cur = s.top()->right;
            if (cur == prev)
                cur = NULL;
            if (!cur) {
                res.push_back(s.top()->val);
                prev = s.top();
                s.pop();
            }
        }
        
        return res;
        
    }
};

