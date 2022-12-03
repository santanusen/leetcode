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
    ListNode* merge2Lists(ListNode* l1, ListNode* l2) {
        ListNode *head = NULL, **tail = &head;
        
        while (l1 && l2) {
            if (l1->val < l2->val) {
                *tail = l1;
                l1 = l1->next;
            } else {
                *tail = l2;
                l2 = l2->next;
            }
            tail = &(*tail)->next;
        }
        
        *tail = (l1 ? l1 : l2);
        
        return head;
    }
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return NULL;
        
        for (int i = 0; i + 1 < lists.size(); i += 2)
            lists.push_back(merge2Lists(lists[i], lists[i + 1]));
        
        return *lists.rbegin();
    }
    
    ListNode* mergeKLists2(vector<ListNode*>& lists) {
        ListNode* head = NULL;
        ListNode **ptail = &head;
        
        int nlists;
        
        do {
            nlists = 0;
            ListNode** minNode = NULL;
            for (auto& list : lists) {
                if (list) {
                    ++nlists;
                    if (!minNode || !(*minNode) || list->val < (*minNode)->val)
                        minNode = &list;
                }
            }
            
            if (minNode && *minNode) {
                *ptail = *minNode;
                ptail = &((*minNode)->next);
                *minNode = (*minNode)->next;
            }
            
        } while (nlists > 1);
        
        return head;
        
    }
};
