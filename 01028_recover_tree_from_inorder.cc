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
    int lpos, llevel, lval, lnpos;

    int getLevelVal(const string& str, int pos, int& level, int& val) {
        if (pos >= str.size()) {
            level = -1;
            val = -1;
            return pos;
        }

        if (pos == lpos) {
            level = llevel;
            val = lval;
            return lnpos;
        }

        lpos = pos;

        level = 0;
        while (pos < str.size() && str[pos] == '-') {
            ++level;
            ++pos;
        }
        llevel = level;

        val = 0;
        while (pos <str.size() && str[pos] != '-') {
            val = val * 10 + (str[pos] - '0');
            ++pos;
        }
        lval = val;

        lnpos = pos;
        return pos;
    }

    TreeNode* dfs(const string& str, int& pos, int level) {
        int ll, vv;
        int posNxt = getLevelVal(str, pos, ll, vv);
        if (ll != level) return NULL;

        pos = posNxt;
        return new TreeNode(vv,
                            dfs(str, pos, level + 1),
                            dfs(str, pos, level + 1));
    }

public:
    TreeNode* recoverFromPreorder(string traversal) {
        lpos = llevel = lval = lnpos = -1;

        int pos = 0;
        return dfs(traversal, pos, 0);
    }

    TreeNode* recoverFromPreorder_iterative(string S) {
        stack<TreeNode*> stk;
        for (int i = 0, level, val; i < S.length();) {
            for (level = 0; S[i] == '-'; i++)
                level++;
            for (val = 0; i < S.length() && S[i] != '-'; i++)
                val = val * 10 + S[i] - '0';
            TreeNode* node = new TreeNode(val);
            while (stk.size() > level)
                stk.pop();
            if (!stk.empty())
                if (!stk.top()->left)
                    stk.top()->left = node;
                else
                    stk.top()->right = node;
            stk.push(node);
        }
        while (stk.size() > 1)
            stk.pop();
        return stk.top();
    }
};
