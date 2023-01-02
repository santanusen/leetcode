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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || !head->next || k < 2) return head; // Trivial cases.

        ListNode** pprev = &head; // End of the previous k group.
        
        // Three pointer link reversal.

        // Initial Setup
        // A -> B -> C
        // ^    ^    ^
        // |    |    |
        // p1   p2   p3
        //
        //
        // After one iteration
        // A -> B   C
        // ^    |
        // |____|
        //
        // ^    ^    ^
        // |    |    |
        // tail p1   p2, p3

        int nn; // Number of nodes in current group.

        ListNode* p1 = head;
        while (p1) {
            ListNode *tail = p1; // This node will eventually be the tail of current group.
            ListNode *p2 = p1->next;

            // Are there enough nodes to reverse?
            nn = 0;
            for (ListNode* pc = p1; pc && nn < k; pc = pc->next) ++nn;
            if (nn == k) {
                for (int i = 0; i < k - 1; ++i) { // Adjust k - 1 links to reverse k nodes.
                    ListNode* p3 = p2->next;
                    p2->next = p1;
                    p1 = p2;
                    p2 = p3;
                }
            }

            *pprev = p1; // p1 is the head of the current group. Link it to tail of previous group.
            pprev = &tail->next; // Remember the tail of current group for next iteration.
            p1 = p2; // Jump to the next group.
            if (nn < k) break;
        }
        if (nn == k) *pprev = NULL;
        return head;
    }
};
