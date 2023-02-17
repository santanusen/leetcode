class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;

        int f1[26] = {0}, f2[26] = {0}; // Frequency tables.

        int cs1 = 0; // Checksum : Just a sum of the alphabets.
        // Calculate frequency table and checksum for s1.
        for (auto ch : s1) {
            int x = ch - 'a';
            ++f1[x];
            cs1 += x;
        }

        int n = s1.length();
        int cs2 = 0; // Rolling checksum.
        // Prepare frequency table and checksum before sliding.
        for (int i = 0; i + 1 < n; ++i) {
            int x = s2[i] - 'a';
            ++f2[x];
            cs2 += x;
        }

        // Sliding window and rolling checksum
        for (int i = 0; i + n - 1 < s2.length(); ++i) {
            // Roll in.
            int x = s2[i + n - 1] - 'a';
            ++f2[x];
            cs2 += x;

            // Is there a match?
            if (cs1 == cs2 && [&](void)->bool{for(int i = 0; i < 26; ++i) if (f1[i] != f2[i]) return false; return true;}())
                return true;

            // Roll out.
            x = s2[i] - 'a';
            --f2[x];
            cs2 -= x;
        }

        return false;
    }
};
