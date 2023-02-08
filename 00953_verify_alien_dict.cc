class Solution {
    bool is_less(const string& s1, const string& s2, const char code[]) {
        int l1 = s1.size(), l2 = s2.size(), l = min(l1, l2);
        for (int i = 0; i < l; ++i) {
            auto c1 = code[s1[i] - 'a'];
            auto c2 = code[s2[i] - 'a'];
            if (c1 != c2) return c1 < c2;
        }
        return l1 < l2;
    }

public:
    bool isAlienSorted(vector<string>& words, string order) {
        char code[26];
        for (int i = 0; i < 26; ++i)
            code[order[i] - 'a'] = i;

        for (int i = 0; i + 1 < words.size(); ++i)
            if (is_less(words[i + 1], words[i], code))
                return false;

        return true;
    }
};
