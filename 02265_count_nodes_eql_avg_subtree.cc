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
    
    int subtreeSum (TreeNode* root, int& numNodes, int& sum) {
        if (!root) {
            numNodes = 0;
            sum = 0;
            return 0;
        }
        int lnum = 0, rnum = 0, lsum = 0, rsum = 0;
        int lneq = subtreeSum(root->left, lnum, lsum);
        int rneq = subtreeSum(root->right, rnum, rsum);
        
        numNodes = lnum + rnum + 1;
        sum = root->val + lsum + rsum;
        return lneq + rneq +
                ((root->val == sum / numNodes) ? 1 : 0);
    }
    
    
public:
    int averageOfSubtree(TreeNode* root) {
        
        int n, s;
        return subtreeSum(root, n, s);
        
    }
};
