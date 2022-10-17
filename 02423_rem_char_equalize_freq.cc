class Solution {
public:
    bool equalFrequency(string word) {
        int freq[26] = {0}; // Frequency of each character
        unordered_map<int, int> hist; // Histogram: Frequency of frequencies.
        int fmax = 0; // Max frequency.
        
        for (char ch : word) {
            int f = ++freq[ch - 'a'];
            if (f - 1 != 0) {
                if(--hist[f - 1] == 0)
                    hist.erase(f -1);       
            }
            ++hist[f];
            
            fmax = max(fmax, f);
        }
        
        auto hsz = hist.size();
        // If there is only a single frequency, then either all the characters
        // in the word should be the same, or all of them should be different.
        // "aaaa" : true  -> hist[4] = 1
        // "abcd" : true  -> hist[1] = 4
        // "aabb" : false -> hist[2] = 2
        //
        // If there are 2 frequencies, then all characters should have the same
        // frequency except one; which has either a frequency of 1 or a frequency
        // which is 1 more than the frequency of all the other characters.
        
        return ((hsz == 1  && (hist[1] == word.length() || fmax == word.length())) ||
                (hsz == 2 &&
                 ((hist[fmax] == 1 && hist[fmax - 1] > 0) || hist[1] == 1)));
        
    }
};
