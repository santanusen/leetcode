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
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode *h = NULL, *t = NULL, *l = head;
        while (l) {
            ListNode* r = l;
            while (r->next && r->next->val == l->val)
                r = r->next;
            if (l == r) {
                if (!h)
                    h = l;
                else
                    t->next = l;
                t = l;
            }
            l = r->next;
        }
        if (t)
            t->next = NULL;
        return h;
    }
};

auto _ = [](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
