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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode *head = NULL;
        ListNode **pnext = &head;
        
        while (list1 && list2) {
            ListNode* cur = NULL;
            if (list1->val < list2->val) {
                *pnext = list1;
                list1 = list1->next;
            } else {
                *pnext = list2;
                list2 = list2->next;
            }
            
            pnext = &((*pnext)->next);
        }
        
        *pnext = (list1) ? list1 : list2;
        return head;
    }
};
