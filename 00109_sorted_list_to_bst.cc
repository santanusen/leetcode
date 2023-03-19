/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* getBST(ListNode* l, ListNode* r) {
        if (l == r) return NULL;
        ListNode *f = l, *s = l;
        while (f != r && f->next != r) {
            s = s->next;
            f = f->next->next;
        }
        return new TreeNode(s->val,
                            getBST(l, s),
                            getBST(s->next, r));
    }

public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return NULL;
        return getBST(head, NULL);
    }
};

class Solution2 {
    TreeNode* getBST(vector<int>& vals, int l, int r) {
        if (l > r) return NULL;
        int m = (l + r) / 2;
        return new TreeNode(vals[m],
                            getBST(vals, l, m - 1),
                            getBST(vals, m + 1, r));
    }

public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return NULL;

        vector<int> vals;
        for (auto cur = head; cur; cur = cur->next)
            vals.push_back(cur->val);

        return getBST(vals, 0, vals.size() - 1);
        
    }
};
