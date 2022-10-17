class Solution {
public:
    bool isValid(string s) {
        
        stack<char> stk;
        
        for (char ch : s) {
            if (ch == '(' || ch == '{' || ch == '[')
                stk.push(ch);
            else {
                if (stk.empty() ||
                    (stk.top() != '(' && ch == ')') ||
                    (stk.top() != '{' && ch == '}') ||
                    (stk.top() != '[' && ch == ']'))
                    return false;
                else
                    stk.pop();
            }
        }
        
        return stk.empty();
        
    }
};
