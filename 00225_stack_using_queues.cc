class MyStack {
    struct Node {
        int val;
        queue<Node*> next;
    };

    queue<Node*> q;

public:
    MyStack() {
        
    }
    
    void push(int x) {
        Node* node = new Node;
        node->val = x;
        node->next.swap(q);
        q.push(node);
    }
    
    int pop() {
        Node *ntop = q.front();
        q.swap(ntop->next);
        int x = ntop->val;
        delete ntop;
        return x;
    }
    
    int top() {
        return q.front()->val;
    }
    
    bool empty() {
        return q.empty();
    }
};

class MyStack2 {
    queue<int> q;
public:
    MyStack2() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        queue<int> q2;
        while (q.size() > 1) {
            q2.push(q.front());
            q.pop();
        }
        int x = q.front();
        q.pop();
        q.swap(q2);
        return x;
    }
    
    int top() {
        int x = pop();
        q.push(x);
        return x;
    }
    
    bool empty() {
        return q.empty();
    }
};
/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
