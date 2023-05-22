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
 static const int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *lead = head, *trail = head, *n1;
        while (--k) lead = lead->next;
        n1 = lead;
        while (lead->next) {
            lead = lead->next;
            trail = trail->next;
        }
        swap(n1->val, trail->val);
        return head;
    }

    ListNode* swapNodes2(ListNode* head, int k) {
        int N = 0;
        for (auto ln = head; ln ; ln = ln->next) ++N;
        int k2 = N + 1 - k;
        int kmax = max(k, k2);
        ListNode *ln1 = NULL, *ln2 = NULL, *ln = head;
        for (int i = 1; i <= kmax; ++i) {
            if (i == k) ln1 = ln;
            if (i == k2) ln2 = ln;
            ln = ln->next;
        }
        swap(ln1->val, ln2->val);
        return head;
    }

};
