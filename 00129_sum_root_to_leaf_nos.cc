class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            auto cur = q.front(); q.pop();
            if (!cur->left && !cur->right)
                sum += cur->val;
            else {
                if (cur->left) {
                    cur->left->val += (10 * cur->val);
                    q.push(cur->left);
                }
                if (cur->right) {
                    cur->right->val += (10 * cur->val);
                    q.push(cur->right);
                }
            }
        }

        return sum;
        
    }
};
