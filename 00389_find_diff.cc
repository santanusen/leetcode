class Solution {
public:
    char findTheDifference(string s, string t) {
        char d = 0;
        for (auto c : s) d ^= c;
        for (auto c : t) d ^= c;
        return d;
    }

    char findTheDifference_diff(string s, string t) {
        int n = s.length(), d = 0;
        for (int i = 0; i < n; ++i)
            d += (t[i] - s[i]);
        return t[n] + d;
    }

    char findTheDifference_freq(string s, string t) {
        int f[26] = {0};
        for (auto c : s) ++f[c - 'a'];
        for (auto c : t) --f[c - 'a'];

        for (int i = 0; i < 26; ++i)
            if (f[i])
                return 'a' + i;

        return '\0';
    }

};

auto _=[](){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();
