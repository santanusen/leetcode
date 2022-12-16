class MyQueue {
    stack<int> push_stack, pop_stack;
    static inline void transfer(stack<int>& src, stack<int>& dst) {
        while (!src.empty()) {
            dst.push(src.top());
            src.pop();
        }
    }
public:
    void push(int x) {
        transfer(pop_stack, push_stack);
        push_stack.push(x);
    }
    
    int pop() {
        int x = peek();
        pop_stack.pop();
        return x;
    }
    
    int peek() {
        transfer(push_stack, pop_stack);
        return pop_stack.top();        
    }
    
    bool empty() {
        return push_stack.empty() && pop_stack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
