class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size(), ans = 0;
        if (n == 3)
            return (s[0] == s[2] ? 1 : 0);

        for (char c = 'a'; c <= 'z'; ++c) {
            int i, j, k;
            for (i = 0; i < n; ++i)
                if (s[i] == c)
                    break;

            for (j = n - 1; j > i + 1; --j)
                if (s[j] == c)
                    break;

            int unq = 0, frq[26] = {0};
            for (k = i + 1; k < j; ++k)
                if (frq[s[k] - 'a']++ == 0)
                    if (++unq == 26)
                        break;

            ans += unq;
        }

        return ans;
        
    }
};

auto _ = [](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
