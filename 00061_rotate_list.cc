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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || !k) return head;
        
        int lsz = 1;
        ListNode* tail = head, *pivot = NULL;
        while (tail->next) {
            if (lsz == k) {
                pivot = head;
            } else if (pivot) {
                pivot = pivot->next;
            }
            tail = tail->next;
            ++lsz;
        }
                
        int rpos = lsz - k % lsz;
        if (rpos == lsz)
            return head;
        
        if (!pivot) {
            pivot = head;
            for (int i = 1; i < rpos; ++i)
                pivot = pivot->next;
        }
        
        tail->next = head;
        head = pivot->next;
        pivot->next = NULL;
        return head;
    }
};

