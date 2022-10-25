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
    TreeNode* BuildBST(vector<int>& nums, int i, int j) {
        if (j < i) return NULL;
        int m = (i + j) >> 1;
        return new TreeNode(nums[m], BuildBST(nums, i, m - 1), BuildBST(nums, m + 1, j));
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return BuildBST(nums, 0, nums.size() - 1);
    }
};
