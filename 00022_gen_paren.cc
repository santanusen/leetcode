class Solution {
    
    void genParenDFS(string s, int op, int cp, vector<string>& res) {
        if (op == 0 && cp == 0) {
            res.push_back(s);
            return;
        }
        
        if (op > 0)
            genParenDFS(s + '(', op - 1, cp, res);
        if (cp > op)
            genParenDFS(s + ')', op, cp - 1, res);
    }
    
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        genParenDFS("", n, n, res);
        return res;
    }
    
    vector<string> generateParenthesis2(int n) {

        vector<string> res;
        
        queue<pair<string, int>> q; // Keep count of opening parenthses.
        
        // BFS
        q.push({"", 0});
        while (!q.empty()) {
            auto p = q.front(); q.pop();

            if (p.first.size() == 2 * n) { // Reached a solution.
                res.push_back(p.first);
            } else {
                int op = p.second; // Number of opening paren.
                int cp = p.first.size() - op; // Number of closing paren.
                if (op < n) // Legal to add an opening parenthesis.
                    q.push({p.first + '(', p.second + 1});
                if (op > cp) // Legal to add a closing parenthesis.
                    q.push({p.first + ')', p.second});
            }
        }
        
        return res;
        
    }
};
