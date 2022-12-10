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
    typedef long long INT;
    INT subTreeSum(TreeNode* root) {
        return ((root) ? INT(root->val) + subTreeSum(root->left) + subTreeSum(root->right) : 0);
    }

    INT minSumDiff(TreeNode* root, INT total, INT& stSum) {
        if (!root) return total;
        INT lsum = 0, rsum = 0;
        INT ldiff = minSumDiff(root->left, total, lsum);
        INT rdiff = minSumDiff(root->right, total, rsum);
        
        stSum = lsum + rsum + root->val;
        INT diff = min(abs(total - (lsum << 1)), abs(total - (rsum << 1))); // <<1 is *2
        return min(ldiff, min(rdiff, diff));
    }

public:
    int maxProduct(TreeNode* root) {
        INT total = subTreeSum(root);
        INT sum;
        INT diff = minSumDiff(root, total, sum);
        // a + b = total
        // a - b = diff
        // a = (total + diff) / 2
        // b = (total - diff) / 2
        INT MOD = 1000000007;
        INT a = (total % MOD + diff % MOD) >> 1; // >>1 is /2
        INT b = ((total - diff) % MOD) >> 1;

        return ((a % MOD) * (b % MOD)) % MOD;
    }
};
