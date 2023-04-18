/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return NULL;
        Node* nmap[101] = {NULL};
        vector<bool> visited(101, false);

        queue<Node*> q;
        q.push(node);
        visited[node->val] = true;
        while (!q.empty()) {
            auto cur = q.front(); q.pop();
            Node* cur2 = (nmap[cur->val]) ? nmap[cur->val] : (nmap[cur->val] = new Node(cur->val));
            for (auto nbr : cur->neighbors) {
                Node* nbr2 = (nmap[nbr->val]) ? nmap[nbr->val] : (nmap[nbr->val] = new Node(nbr->val));
                cur2->neighbors.push_back(nbr2);
                if (!visited[nbr->val]) {
                    q.push(nbr);
                    visited[nbr->val] = true;
                }
            }
        }

        return nmap[node->val];
    }
};
