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

 #if 1
class Solution {
    ListNode* rev(ListNode *head) {
        ListNode* curr = head;
        ListNode* prev = NULL;

        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = rev(l1);
        l2 = rev(l2);

        ListNode *l3 = NULL;
        int carry = 0;

        while (l1 || l2 || carry) {
            int sum = carry;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;
            ListNode* node = new ListNode(sum % 10, l3);
            l3 = node;
        }

        return l3;
    }
};

#else

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        uint8_t n1[100], n2[100];
        int i = -1, j = -1;

        while (l1) {
            n1[++i] = l1->val;
            l1 = l1->next;
        }

        while(l2) {
            n2[++j] = l2->val;
            l2 = l2->next;
        }

        int c = 0;
        ListNode* l3 = NULL;

        while (c || i > -1 || j > -1) {
            int s = c;
            if (i > -1)
                s += n1[i--];

            if (j > -1)
                s += n2[j--];

            c = s / 10;

            ListNode *node = new ListNode(s % 10, l3);
            l3 = node;
        }

        return l3;
    }
};
#endif

auto _ = [](){ios::sync_with_stdio(false); cin.tie(0); cout.tie(0); return 0;}();
