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

    ListNode *lhead;

    int distFromEnd(ListNode* cur, int n) {
        if (!cur) return 0;
        auto cdepth = distFromEnd(cur->next, n);
        if (cdepth == n)
            cur->next = cur->next->next;

        return cdepth + 1;
    }

public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        return ((distFromEnd(head, n) == n) ? head->next : head);
    }

    ListNode* removeNthFromEnd2(ListNode* head, int n) {
        auto r = head;
        while (n--) r = r->next;
        if (!r) return head->next;

        auto l = head;
        while (r->next) {
            r = r->next;
            l = l->next;
        }
        l->next = l->next->next;
        return head;
    }
};
