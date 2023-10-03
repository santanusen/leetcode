class Solution {
    typedef uint64_t Int;
public:
    string decodeAtIndex(string s, int k) {
        stack<tuple<string, Int, int>> stk;

        string w;
        Int len = 0;
        for (auto c : s) {
            if (isdigit(c)) {
                int rpt = c - '0';
                stk.push({w, len, rpt});
                w.clear();
                len *= rpt;
            } else {
                w.push_back(c);
                ++len;
                if (len >= k)
                    stk.push({w, len, 1});
            }
            if (len >= k)
                break;
        }

        Int kk = k - 1;
        while (!stk.empty()) {
            auto [str, len, rpt] = stk.top();
            kk %= len;

            Int chlen = len - str.length();
            if (kk >= chlen)
                return {str[kk - chlen]};

            stk.pop();
        }

        return "";
        
    }
};
