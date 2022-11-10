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
    
    TreeNode* buildTree(vector<int>& nums, int i, int j) {
        if (j < i) return NULL;
        int m = i;
        for (int k = i + 1; k <= j; ++k)
            m = (nums[k] > nums[m]) ? k : m;
        return new TreeNode(nums[m], buildTree(nums, i, m - 1), buildTree(nums, m + 1, j));
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return buildTree(nums, 0, nums.size() -1);
    }
};
