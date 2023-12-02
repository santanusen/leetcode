class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int freq[26] = {0};
        for (auto ch : chars)
            ++freq[ch - 'a'];

        int ans = 0;
        for (auto& w : words) {
            if (w.length() > chars.length()) continue;
            int fw[26] = {0};
            bool good = true;
            for (auto ch : w)
                if (++fw[ch - 'a'] > freq[ch - 'a']) {
                    good = false;
                    break;
                }
            if (good)
                ans += w.length();
        }

        return ans;
        
    }
};

auto _=[](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
