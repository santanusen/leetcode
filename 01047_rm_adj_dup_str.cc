class Solution {
public:
    /*
    string removeDuplicates(string s) {
        for (int i = 0; i + 1 < s.size(); ++i)
            if (s[i] == s [i + 1]) {
                s.erase(i, 2);
                i = max(i - 2, -1);
            }
        return s;
    }
    */
    
    string removeDuplicates(string s) {
        int i = 0;
        for (int j = 0; j < s.length(); ++j, ++i) {
            s[i] = s[j];
            if (i > 0 && s[i - 1] == s[i])
                i -= 2;
        }
        return s.substr(0, i);
    }
};
