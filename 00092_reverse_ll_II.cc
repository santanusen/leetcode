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
    ListNode *pred = 0, *succ = 0, *nhead = 0;

    ListNode* rev(ListNode* cur, int pos, int l, int r) {
        if (pos == l - 1)
            pred = cur;
        
        if (pos == r) {
            succ = cur->next;
            cur->next = nullptr;
            if (pred)
                pred->next = cur;
            else
                nhead = cur;
            return cur;
        }

        auto rtail = rev(cur->next, pos + 1, l, r);
        if (pos >= l)
            rtail->next = cur;

        if (pos == l)
            cur->next = succ;

        return cur;
    }

public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right)
            return head;

        rev(head, 1, left, right);
        return (nhead ? nhead : head);
    }
};
