class Solution {
    bool matchhere(const char* rgx, const char* txt) {
        if (rgx[0] == '\0') return false;
        if (rgx[1] == '*') return matchstar(rgx[0], rgx + 2, txt);
        if (rgx[0] == '$') return txt[0] == '\0';
        if (txt[0] != '\0' && (rgx[0] == txt[0] || rgx[0] == '.'))
            return matchhere(rgx + 1, txt + 1);

        return false;
    }

    bool matchstar(char c, const char* rgx, const char* txt) {
        do {
            if (matchhere(rgx, txt))
                return true;
        } while(*txt != '\0' && (*txt++ == c || c == '.'));

        return false;
    }
public:
    bool isMatch(string s, string p) {
        p += '$';
        return matchhere(p.c_str(), s.c_str());        
    }
};
