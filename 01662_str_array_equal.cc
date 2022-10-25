class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        
        int i1 = 0, i2 = 0;
        int j1 = 0, j2 = 0;
        while (i1 < word1.size() && i2 < word2.size()) {
            bool wchg = false;
            if (j1 == word1[i1].length()) {
                ++i1;
                j1 = 0;
                wchg = true;
            }
            if (j2 == word2[i2].length()) {
                ++i2;
                j2 = 0;
                wchg = true;
            }
            if (!wchg && word1[i1].at(j1++) != word2[i2].at(j2++))
                return false;
        }
        
        return (i1 == word1.size() && i2 == word2.size());
        
    }
};
