class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.length() != goal.length()) return false;

        int mm[2], im = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] != goal[i])
                if (im > 1)
                    return false;
                else
                    mm[im++] = i;
        }

        if (im == 0) {
            int freq[26] = {0};
            for (auto ch : s)
                if (freq[ch - 'a']++) return true;
            return false;
        }

        if (im == 1) return false;

        return (s[mm[0]] == goal[mm[1]] && s[mm[1]] == goal[mm[0]]);
        
    }
};
