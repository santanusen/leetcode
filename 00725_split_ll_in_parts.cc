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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        if (k == 1) return {head};

        vector<ListNode*> ans(k, nullptr);

        ListNode* cur;
        int len = 0;
        for (cur = head; cur; cur = cur->next)
            ++len;

        int l = len / k, e = len % k;

        cur = head;
        for (int i = 0; i < k; ++i) {
            int s = l + (i < e ? 1 : 0);
            if (s == 0)
                break;
            ans[i] = cur;
            for (int j = 1; j < s; ++j)
                cur = cur->next;

            auto tmp = cur->next;
            cur->next = nullptr;
            cur = tmp;
        }

        return ans;
        
    }
};

auto _ = [](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
