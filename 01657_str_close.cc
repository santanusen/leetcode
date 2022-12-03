class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.length() != word2.length()) // Can't introduce extra characters.
            return false;
        
        // Calculate character frequencies for each string.
        // Positions does not matter as operation 1 can align positions.
        int freq1[26] = {0}, freq2[26] = {0};
        for (int i = 0; i < word1.size(); ++i) {
            ++freq1[word1[i] - 'a'];
            ++freq2[word2[i] - 'a'];
        }
        
        // Remember mismatched frequencies.
        unordered_map<int, int> mm1, mm2;
        for (int i = 0; i < 26; ++i)
            if (freq1[i] != freq2[i]) {
                if (!freq1[i] || !freq2[i]) // Can't introduce/remove a new char.
                    return false;
                
                ++mm1[freq1[i]];
                ++mm2[freq2[i]];
            }
        
        
        // If mismatched frequencies are the same in both the strings
        // operation 2 can fix them.
        return mm1 == mm2;
        
    }
};
