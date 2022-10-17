class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty())
            return "";
        if (strs.size() == 1)
            return strs[0];
        
        int pos = 0;
        string pref;
        while (true) {
            char c = '\0';
            for (const auto& s : strs) {
                if (pos >= s.length()) {
                    c = '\0';
                    break;
                }
                if (c == '\0')
                    c = s.at(pos);
                else if (s.at(pos) != c) {
                    c = '\0';
                    break;
                }
            } // for
            
            if (c == '\0')
                break;
            pref.push_back(c);
            ++pos;
        } // while
        
        return pref;
        
    }
};
