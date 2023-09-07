/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList_hmap(Node* head) {
        if (!head) return head;

        unordered_map<Node*, Node*> ntbl;
        ntbl[nullptr] = nullptr;
        Node* head2 = new Node(head->val);
        ntbl[head] = head2;

        Node *cur2 = head2, *cur = head->next;
        while (cur) {
            cur2->next = new Node(cur->val);
            cur2 = cur2->next;
            ntbl[cur] = cur2;
            cur = cur->next;
        }

        cur = head, cur2 = head2;
        while (cur) {
            cur2->random = ntbl[cur->random];
            cur = cur->next;
            cur2 = cur2->next;
        }

        return head2;
    }

    Node* copyRandomList(Node* head) {
        if (!head) return head;

        Node* cur = head;
        while (cur) {
            Node* nxt = cur->next;
            cur->next = new Node(cur->val);
            cur->next->next = nxt;
            cur = nxt;
        }

        cur = head;
        while (cur) {
            if (cur->random)
                cur->next->random = cur->random->next;
            cur = cur->next->next;
        }

        Node* head2 = head->next;
        cur = head;
        while (cur) {
            Node* cur2 = cur->next;
            cur->next = cur2->next;
            cur2->next = (cur->next ? cur->next->next : nullptr);
            cur = cur->next;
        }

        return head2;
    }
};

auto _ = [](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
