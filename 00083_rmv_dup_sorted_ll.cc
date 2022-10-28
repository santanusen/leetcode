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
        if (!head) return head;
        
        ListNode *i = head;
        while(i) {
            ListNode* j = i->next;
            while (j && j->val == i->val)
                j = j->next;
            i->next = j;
            i = j;
        }
        return head;
    }
};
