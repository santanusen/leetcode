class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int last_seen_at[128];
        for (int i = 0; i < 128; ++i)
            last_seen_at[i] = -1;
        
        int mlen = 0, bcur = 0;
        
        for (int i  = 0; i < s.length(); ++i) {
            if (last_seen_at[s.at(i)] >= bcur) {
                mlen = max(mlen, i - bcur);
                bcur = last_seen_at[s.at(i)] + 1;
            }
            
            last_seen_at[s.at(i)] = i;
        }
        
        return max(mlen, static_cast<int>(s.length()) - bcur);
    }
};
