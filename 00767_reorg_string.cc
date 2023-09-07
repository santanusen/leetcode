class Solution {
public:
    string reorganizeString(string s) {
        int freq[26] = {0}, fmax = 0, n = s.size();
        char mfc = '\0';
        for (auto ch : s)
            if (++freq[ch - 'a'] > fmax)
                fmax = freq[ch - 'a'], mfc = ch;

        if (fmax > n - fmax + 1)
            return "";

        vector<string> slots(fmax, string{mfc});
        freq[mfc - 'a'] = 0;

        for (int i = 0, sid = 0; i < 26; ++i)
            for (int f = 0; f < freq[i]; ++f, sid = (sid + 1) % fmax)
                slots[sid].push_back('a' + i);

        string ans;
        for (auto& ss : slots)
            ans.append(ss);

        return ans;
    }
};
