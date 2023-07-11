class Solution {
public:
    int largestVariance(string s) {
        int vmax = 0;
        for (char a = 'a'; a < 'z'; ++a) {
            for (char b = a + 1; b <= 'z'; ++b) {
                int amax = 0, acsum = 0, bmax = 0, bcsum = 0, af = 0, bf = 0;
                bool hasa = false, hasb = false;
                for (auto ch : s) {
                    if (ch == a) {
                        ++af;

                        ++acsum;
                        amax = max(((hasb) ? acsum : acsum - 1), amax);

                        --bcsum;
                        hasa = true;
                        if (bcsum < 0) {
                            bcsum = 0;
                            hasa = false;
                        }

                    } else if (ch == b) {
                        ++bf;

                        ++bcsum;
                        bmax = max(((hasa) ? bcsum : bcsum - 1), bmax);

                        --acsum;
                        hasb = true;
                        if (acsum < 0) {
                            acsum = 0;
                            hasb = false;
                        }
                    }
                }

                if ((af < 2 && bf < 2) || af == 0 || bf == 0)
                    continue;

                vmax = max({vmax, amax, bmax});
            }
        }

        return vmax;
    }

    int largestVariance2(string s) {
        int n = s.size();
        int freq[n + 1][26];

        int f[26] = {0};
        memcpy(freq[0], f, sizeof(f));

        for (int i = 0; i < n; ++i) {
            ++f[s[i] - 'a'];
            memcpy(freq[i + 1], f, sizeof(f));
        }

        int vmax = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (i + vmax + 1 >= n) break;
            for (int j = n - 1; j >= i + vmax + 1; --j) {
                int dmax = INT_MIN, dmin = INT_MAX;
                for (int c = 0; c < 26; ++c) {
                    int frq = freq[j + 1][c] - freq[i][c];
                    if (frq != 0) {
                        dmax = max(dmax, frq);
                        dmin = min(dmin, frq);
                    }
                }
                vmax = max(vmax, dmax - dmin);
            }
        }

        return vmax;
        
    }
};

auto _=[](){ios::sync_with_stdio(false); cin.tie(0); cout.tie(0); return 0;}();
