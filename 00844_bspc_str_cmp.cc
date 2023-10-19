class Solution {
public:
    bool backspaceCompare(string s, string t) {
        char s1[s.length() + 1], s2[t.length() + 1];

        int i = 0, j = 0;

        for (auto ch : s)
            if (ch == '#')
                i = (i > 0 ? i - 1 : 0);
            else
                s1[i++] = ch;
        s1[i] = '\0';

        for (auto ch : t)
            if (ch == '#')
                j = (j > 0 ? j - 1 : 0);
            else
                s2[j++] = ch;
        s2[j] = '\0';

        return (i == j && !strcmp(s1, s2));
    }
};
