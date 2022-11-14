/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head) return false;
        
        for (auto fast = head->next; fast && fast->next; head = head->next, fast = fast->next->next)
            if (head == fast)
                return true;
        
        return false;
        
    }
};
