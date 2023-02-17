class Solution {
public:
    int prec(char op) {
        switch (op) {
                case ')': return 1;

                case '+':
                case '-': return 10;

                case '*':
                case '/': return 20;

                case '@': return 50;

                case '(': return 100;

                default: break;
        }

        return -1;
}

int cmp_prec(char op1, char op2) {
        return ((op1 == '(' || op2 == '(') ? -100 : (prec(op1) - prec(op2)));
}

int operate(char op, int n1, int n2) {
        switch (op) {
                case '+': return n1 + n2;
                case '-': return n1 - n2;
                case '*': return n1 * n2;
                case '/': return n1 / n2;
                case '@': return -n1;

                default:
                        break;
        }

        return 0;
}

void compress_stacks(stack<char>& os, stack<int>& ns, char cur_op) {
        while (!os.empty() && cmp_prec(os.top(), cur_op) >= 0) {
                auto op = os.top(); os.pop();
                auto n2 = 0;
                if (op != '@') {
                        n2 = ns.top(); ns.pop();
                }
                auto n1 = ns.top(); ns.pop();
                ns.push(operate(op, n1, n2));
        }
}

int calculate (string s) {
        s += '\0';
        stack<char> os;
        stack<int> ns;

        int num = 0;
        bool in_num = false;
        char last_tok = '(';

        for (int i = 0; i < s.size(); ++i) {
                if (isdigit(s[i])) {
                        if (!in_num)
                                in_num = true;

                        num = 10 * num + (s[i] - '0');
                        last_tok = s[i];
                } else {
                        if (in_num) {
                                in_num = false;
                                ns.push(num);
                                num = 0;
                        }

                        if (prec(s[i]) != -1) {
                                if (last_tok != ')' && prec(last_tok) != -1 && s[i] == '-') {
                                        s[i] = '@';
                                }
                                compress_stacks(os, ns, s[i]);

                                if (s[i] == ')')
                                        os.pop();
                                else
                                        os.push(s[i]);

                                last_tok = s[i];
                        }
                }
        }

        compress_stacks(os, ns, '$');
        return (ns.empty() ? 0 : ns.top());
}

};
