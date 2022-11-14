class Solution {
public:
    string reverseWords(string s) {
        // Reverse the whole thing.
        reverse(s.begin(), s.end());
        
        // Now revrse individual words.
        int ins = 0; // Insert position.
        int wb = -1; // Index of beginning of current word.
        
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != ' ') {
                if (wb == -1) // Start of a new word.
                    wb = i;
            } else // Outside word.
                wb = -1;
            
            if (wb > -1 && (i == s.size() - 1 || s[i + 1] == ' ')) { // A word just ended.
                // Reverse the word.
                reverse(s.begin() + wb, s.begin() + i + 1);
                // Add word separator.
                if (ins > 0) s[ins++] = ' ';
                // Copy the word at insert position.
                for (int w = wb; w <= i; ++w)
                    s[ins++] = s[w];
            }
        }
        
        s.erase(ins, string::npos); // Get rid of trailing chars.
        
        return s;
    }
};

