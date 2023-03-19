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
    TreeNode* build(vector<int>& inorder, vector<int>& postorder,
    int il, int ir, int pl, int pr) {
        // Base cases
        if (ir < il) return NULL;
        if (il == ir) return new TreeNode(inorder[il]);

        // Root is the right-most of postorder.
        int rootv = postorder[pr];
        TreeNode* root = new TreeNode(rootv);

        // Locate root in inorder.
        int im = ir;
        while (inorder[im] != rootv)
            --im;

        // Count number of nodes in right subtree.
        int rscnt = ir - im;

        // Recurse.
        root->right = build(inorder, postorder, im + 1, ir, pr - rscnt, pr - 1);
        root->left = build(inorder, postorder, il, im - 1, pl, pr - rscnt - 1);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        return build(inorder, postorder, 0, n - 1, 0, n - 1);
    }
};
