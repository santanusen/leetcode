class Solution {
    static inline bool isVowel(char c) {
        switch (c) {
            case 'a': case 'e': case 'i': case 'o': case 'u':
            case 'A': case 'E': case 'I': case 'O': case 'U':
                return true;
            default:
                return false;
        }
    }
    
public:
    string reverseVowels(string s) {
        int i = 0; int j = s.size() - 1;
        while (i < j) {
            while (i < j && !isVowel(s[i]))
                ++i;
            while (i < j && !isVowel(s[j]))
                --j;
            if (i < j)
                swap(s[i++], s[j--]);
        }
        
        return s;
    }
};
