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
    int pairSum(ListNode* head) {
        ios::sync_with_stdio(false); cin.tie(NULL); cin.tie(nullptr);

        // Get to middle node.
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse second half.
        ListNode *nxt, *prv = NULL;
        while (slow) {
            nxt = slow->next;
            slow->next = prv;
            prv = slow;
            slow = nxt;
        }

        int ans = INT_MIN;
        ListNode *l1 = head, *l2 = prv;
        while (l2) {
            ans = max(ans, l1->val + l2->val);
            l1 = l1->next;
            l2 = l2->next;
        }

        return ans;
    }

    int pairSum2(ListNode* head) {
        ios::sync_with_stdio(false); cin.tie(NULL); cin.tie(nullptr);
        
        vector<int> nums;
        for (; head; head = head->next)
            nums.push_back(head->val);
        int i = 0, j = nums.size() - 1, ans = INT_MIN;
        while(i < j)
            ans = max(ans, nums[i++] + nums[j--]);
        return ans;
    }
};
