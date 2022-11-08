class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int pairs = 0;
        int unpaired_pal = 0;
        
        unordered_map<string, int> t; // Unpaired non-palindromic words
        //unordered_map<string, int> unpaired_pal; // Unpaired palindromic words
        
        for (auto &w : words) {
            bool pal = (w[0] == w[1]);
            // unordered_map<string, int>& t = ((pal) ? unpaired_pal : unpaired);
            
            auto rw = w;
            if (!pal)
                reverse(rw.begin(), rw.end());
            if (t.count(rw)) {
                if (--t[rw] == 0)
                    t.erase(rw);
                ++pairs;
                if (pal) --unpaired_pal;
            } else {
                ++t[w];
                if (pal) ++unpaired_pal;
            }
        }
        
        // We can place at max one unpaired palindromic word in the middle.
        return ((unpaired_pal ? 2 : 0) + 4 * pairs);
    }
};
