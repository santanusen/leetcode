class Solution {
public:
    int strStr(string haystack, string needle) {
        if (haystack.size() < needle.size()) return -1;
        unsigned int nh = 0; // Needle Hash
        for (auto ch : needle) nh ^= ch;

        unsigned int hh = 0; // Haystack Hash
        for (int i = 0; i + 1 < needle.size(); ++i) hh ^= haystack[i];

        // Keep sliding the window and rolling the hash.
        for (int i = 0; i + needle.size() <= haystack.size(); ++i) {
            hh ^= haystack[i + needle.size() - 1]; // Roll in.
            if (nh == hh && haystack.compare(i, needle.size(), needle) == 0)
                return i;
            hh ^= haystack[i]; // Roll out.
        }

        return -1;
        
    }
};
