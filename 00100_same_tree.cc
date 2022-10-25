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
    bool isSameTreeRec(TreeNode* p, TreeNode* q) {
        if (!p && !q)
            return true;
        if  (p && q && p->val == q->val)
            return (isSameTreeRec(p->left, q->left) && isSameTreeRec(p->right, q->right));
        return false;       
    }
    
    bool check(TreeNode* p, TreeNode* q){
        if (p == q)
            return true;
        if (!p || !q)
            return false;
        return (p->val == q->val);
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> qp, qq;
        qp.push(p);
        qq.push(q);
        
        while (!qp.empty()) {
            p = qp.front(); qp.pop();
            q = qq.front(); qq.pop();
            if (!check(p, q))
                return false;
            if (p) {
                qp.push(p->left);
                qq.push(q->left);
                
                qp.push(p->right);
                qq.push(q->right);
            }
        }
        
        return true;
        
    }
};
