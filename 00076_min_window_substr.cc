class Solution {
    static inline int ch2idx(char ch) {
        return (isupper(ch) ? ch - 'A' : ch - 'a' + 26);
    }

public:
    string minWindow(string s, string t) {
        int tf[52] = {0}, sf[52] = {0};
        for (auto ch : t) ++tf[ch2idx(ch)];

        int L = 0, R = s.size(), n = 0;
        int l = 0;

        for (int i = 0; i < s.size(); ++i) {
            auto idx = ch2idx(s[i]);
            if (!tf[idx]) continue;
            ++sf[idx];
            if (sf[idx] <= tf[idx]) {
                ++n;
                if (n == t.size()) {
                    int idl;
                    while ((idl = ch2idx(s[l])) < 52 &&
                            (sf[idl] == 0 || sf[idl] > tf[idl])) {
                        if (sf[idl]) --sf[idl];
                        ++l;
                    }
                    if (i - l < R - L) {
                        L = l;
                        R = i;
                    }
                    idl = ch2idx(s[l]);
                    --sf[idl];
                    --n;
                    ++l;
                }
            }
        }

        return ((R < s.size()) ? s.substr(L, R - L + 1) : "");
    }
};
