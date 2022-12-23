class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long> s;
        for (auto& tok : tokens) {
            if (!isdigit(tok[0]) && tok.length() == 1) {
                long op2 = s.top(); s.pop();
                long op1 = s.top(); s.pop();
                long res;
                switch (tok[0]) {
                    case '+': res = op1 + op2; break;
                    case '-': res = op1 - op2; break;
                    case '*': res = op1 * op2; break;
                    case '/': res = op1 / op2; break;
                }
                s.push(res);
            } else{
                s.push(stoi(tok));
            }
        }

        return s.top();
        
    }
};
