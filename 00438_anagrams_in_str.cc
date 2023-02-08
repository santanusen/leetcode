class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (p.length() > s.length()) return {};

        int f1[26] = {0}, f2[26] = {0}; // Frequency tables.

        int cs1 = 0; // Checksum : Just a sum of the alphabets.
        // Calculate frequency table and checksum for p.
        for (auto ch : p) {
            int x = ch - 'a';
            ++f1[x];
            cs1 += x;
        }

        int n = p.length();
        int cs2 = 0; // Rolling checksum.
        // Prepare frequency table and checksum before sliding.
        for (int i = 0; i + 1 < n; ++i) {
            int x = s[i] - 'a';
            ++f2[x];
            cs2 += x;
        }

        vector<int> res;
        // Sliding window and rolling checksum
        for (int i = 0; i + n - 1 < s.length(); ++i) {
            // Roll in.
            int x = s[i + n - 1] - 'a';
            ++f2[x];
            cs2 += x;

            // Is there a match?
            if (cs1 == cs2) {
                int j;
                for (j = 0; j < 26; ++j)
                    if (f1[j] != f2[j])
                        break;
                if (j == 26) res.push_back(i);
            }

            // Roll out.
            x = s[i] - 'a';
            --f2[x];
            cs2 -= x;
        }

        return res;  
    }
};
