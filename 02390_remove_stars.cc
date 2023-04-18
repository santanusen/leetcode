class Solution {
public:
    string removeStars(string s) {
        int i = 0;
        for (auto ch : s)
            if (ch != '*')
                s[i++] = ch;
            else
                --i;
        s.resize(i);
        return s;
        //return s.substr(0, i);
    }

    string removeStars2(string s) {
        char res[s.size() + 1];

        int i = 0;
        for (auto ch : s)
            if (ch != '*')
                res[i++] = ch;
            else
                --i;
        res[i] = '\0';

        return res;
    }
};
