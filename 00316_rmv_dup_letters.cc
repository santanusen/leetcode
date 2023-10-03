class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> stk;
        vector<bool> seen(26);
        int lpos[26];

        for (int i = 0; i < s.length(); ++i)
            lpos[s[i] - 'a'] = i;

        for (int i = 0; i < s.length(); ++i) {
            auto c = s[i];
            if (!seen[c- 'a']) {
                while (!stk.empty() && c < stk.top() && i < lpos[stk.top() - 'a']) {
                    seen[stk.top() - 'a'] = false;
                    stk.pop();
                }
                seen[c - 'a'] = true;
                stk.push(c);
            }
        }

        string ans;
        while (!stk.empty()) {
            ans.push_back(stk.top());
            stk.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

auto _ = [](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
