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
    int last = INT_MAX;
    int frq = 0;
    int fmax = INT_MIN;

    void inTrav(TreeNode* cur, vector<int>& ans) {
        if (!cur) return;
        
        if (cur->left)
            inTrav(cur->left, ans);
        
        if (cur->val == last)
            ++frq;
        else
            frq = 1;

        if (frq > fmax) {
            ans.clear();
            fmax = frq;
        }
        
        if (frq == fmax)
            ans.push_back(cur->val);

        last = cur->val;
        
        if (cur->right)
            inTrav(cur->right, ans);
    }

public:
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        inTrav(root, ans);
        return ans;
    }
};

class Solution2 {
    void inTrav(TreeNode* cur, unordered_map<int, int>& frq) {
        if (cur) {
            ++frq[cur->val];
            inTrav(cur->left, frq);
            inTrav(cur->right, frq);
        }
    }
public:
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> frq;
        inTrav(root, frq);
        
        set<pair<int, int>> sfreq;
        for (auto [v, f] : frq)
            sfreq.insert({f, v});

        vector<int> ans;
        int fmax = INT_MIN;
        for (auto itr = sfreq.rbegin(); itr != sfreq.rend();  ++itr) {
            if (itr->first < fmax)
                break;
            fmax = itr->first;
            ans.push_back(itr->second);
        }

        return ans;
        
    }
};

auto _ = [](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
