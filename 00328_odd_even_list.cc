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
    ListNode* oddEvenList(ListNode* head) {
        bool odd = true;
        ListNode *oh = NULL, *eh = NULL, **ot = &oh, **et = &eh;
        while (head) {
            if (odd) {
                *ot = head;
                ot = &(head->next);
            } else {
                *et = head;
                et = &(head->next);
            }
            head = head->next;
            odd = !odd;
        }
        if (oh) *ot = eh;
        if (eh) *et = NULL;

        return oh;
        
    }
};
