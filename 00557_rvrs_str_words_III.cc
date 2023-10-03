class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        for (int i = 0, wb = 0; i <= n; ++i) {
            if (i == n || s[i] == ' ') {
                if (wb < i)
                    reverse(s.begin() + wb, s.begin() + i);
                wb = i + 1;
            }
        }

        return s;
    }
};

auto _ = [](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
