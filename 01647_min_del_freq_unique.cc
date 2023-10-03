class Solution {
public:
    int minDeletions(string s) {
        int freq[26] = {0};
        for (auto c : s)
            ++freq[c - 'a'];

        map<int, int> tbl;
        for (int i = 0; i < 26; ++i)
            if (freq[i])
                ++tbl[freq[i]];

        int ans = 0;
        for (auto [f, l] : tbl) {
            int ff = f;
            while (l > 1) {
                ans += (f - ff);
                while (tbl[ff] > 0) {
                    --ff;
                    ++ans;
                }
                if (ff > 0)
                    tbl[ff] = 1;
                --l;
            }
            tbl[f] = 1;
        }
        
        return ans;
    }
};
