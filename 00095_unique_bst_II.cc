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

    const vector<TreeNode*> nullTree = {NULL};

    const vector<TreeNode*>& buildTrees(int low, int high, vector<vector<vector<TreeNode*>>>& memo) {
        if (low > high) return nullTree;
        if (!memo[low - 1][high - 1].empty()) return memo[low - 1][high - 1];

        if (low == high) {
            memo[low - 1][high - 1].push_back(new TreeNode(low));
            return memo[low - 1][high - 1];
        }

        for (int pivot = low; pivot <= high; ++pivot) {
            auto lsubs = buildTrees(low, pivot - 1, memo);
            auto rsubs = buildTrees(pivot + 1, high, memo);

            for (auto ls : lsubs)
                for (auto rs : rsubs)
                    memo[low - 1][high - 1].push_back(new TreeNode(pivot, ls, rs));
        }

        return memo[low - 1][high - 1];
    }

public:

    vector<TreeNode*> generateTrees(int n) {
#if 1
        vector<TreeNode*>* memo[n][n];

        for (int i = 1; i <= n; ++i) {
            memo[i - 1][i - 1] = new vector<TreeNode*> {new TreeNode(i)};
        }

        for (int d = 1; d <= n - 1; ++d) {
            int lmax = n - d;
            for (int low = 1; low <= lmax; ++low) {
                int high = low + d;
                memo[low - 1][high - 1] = new vector<TreeNode*>();
                for (int pivot = low; pivot <= high; ++pivot) {
                    const vector<TreeNode*>& lss = ((pivot - 1 < low) ? nullTree : *memo[low - 1][pivot - 2]);
                    const vector<TreeNode*>& rss = ((pivot + 1 > high) ? nullTree : *memo[pivot][high - 1]);
                    for (auto ls : lss)
                        for (auto rs : rss)
                            memo[low - 1][high - 1]->push_back(new TreeNode(pivot, ls, rs));
                }
            }
        }

        return *memo[0][n - 1];

#else
        vector memo(n, vector(n, vector<TreeNode*>()));
        return buildTrees(1, n, memo);
#endif

    }
};

auto _ = [](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
