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
    ListNode* partition(ListNode* head, int x) {
        ListNode *lhead = 0, *ltail = 0, *rhead = 0, *rtail = 0;

        while (head) {
            ListNode* nxt = head->next;
            head->next = NULL;

            if (head->val < x) {
                if (!ltail)
                    lhead = ltail = head;
                else {
                    ltail->next = head;
                    ltail = head;
                }
            } else {
                if (!rtail)
                    rhead = rtail = head;
                else {
                    rtail->next = head;
                    rtail = head;
                }
            }

            head = nxt;
        }

        if (!lhead)
            return rhead;

        ltail->next = rhead;
        return lhead;
    }
};

auto _ = [](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
