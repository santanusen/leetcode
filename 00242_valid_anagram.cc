class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;

        int f[26] = {0};
        for (auto c : s) ++f[c - 'a'];
        for (auto c : t) if (--f[c - 'a'] < 0) return false;

        return true;
    }
};

auto _ = [](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
