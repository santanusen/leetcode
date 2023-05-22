static const int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
    inline bool is_vowel(char& c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        /*static bool vmap[] = {1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0};
        return vmap[c - 'a']; */
        /*switch(c) {
            case 'a': case 'e': case 'i': case 'o': case 'u':
                return true;
        }
        return false;*/
    }
public:
    int maxVowels(string s, int k) {
        int nv = 0, vmax = 0;
        for (int i = 0; i < k; ++i)
            if (is_vowel(s[i])) ++nv;
        vmax = nv;
        for (int i = 0, j = k; j < s.length(); ++i, ++j) {
            if (is_vowel(s[i])) --nv;
            if (is_vowel(s[j])) ++nv;
            //nv += (static_cast<int>(is_vowel(s[j])) - static_cast<int>(is_vowel(s[i])));
            if ((vmax = max(vmax, nv)) == k) return k;
            //vmax = max(vmax, nv);
        }
        return vmax;
    }
};
