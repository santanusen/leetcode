class Solution {
    static inline bool isvowel(char ch) {
        switch (ch) {
            case 'a': case 'e': case 'i': case 'o': case 'u':
            case 'A': case 'E': case 'I': case 'O': case 'U':
                return true;
            default:
                return false;
        }
    }
    
public:
    bool halvesAreAlike(string s) {
        int v = 0;
        
        const int H = s.size() / 2;
        for (int i = 0; i < H; ++i) {
            if (isvowel(s[i])) ++v;
            if (isvowel(s[H + i])) --v;
        }
        
        return v == 0;
    }
};
