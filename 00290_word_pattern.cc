class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> pmap;
        unordered_map<string, char> smap;

        int i = 0;
        for (auto p : pattern) {
            string word;
            char ch;
            while (i < s.size() && (ch = s[i++]) != ' ')
                word.push_back(ch);
            if (word.empty()) return false;
            if (pmap.find(p) != pmap.end() && pmap[p] != word) return false;
            if (smap.find(word) != smap.end() && smap[word] != p) return false;
            pmap[p] = word;
            smap[word] = p;
        }

        return (i == s.size());
    }
};
