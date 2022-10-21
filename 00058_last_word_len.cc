class Solution {
public:
    int lengthOfLastWord(string s) {
        bool in_word = false;
        int l = 0;
        for (int i = s.length() - 1; i >= 0; --i) {
            if (s.at(i) != ' ') {
                in_word = true;
                ++l;
            } else {
                if (in_word)
                    break;
            }
        }
        
        return l;
    }
};
