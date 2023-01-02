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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode** pprev = &head;
        ListNode* p1 = head;
        while (p1) {
            ListNode* p2 = p1->next;
            ListNode* p3 = ((p2) ? p2->next : NULL);

            *pprev = (p2 ? p2 : p1);
            if (p2) p2->next = p1;
            pprev = &p1->next;
            p1 = p3;
        }
        *pprev = NULL;
        return head;
        
    }
}
