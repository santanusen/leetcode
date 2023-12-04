class Solution {
public:
    string largestGoodInteger(string num) {
        int len = 0, pd = -1, nmax = -1;
        for (auto d : num) {
            int i = d - '0';
            if (i == pd) {
                if (++len > 2 && (nmax = max(nmax, i)) == 9)
                    break;
            } else {
                pd = i;
                len = 1;
            }
        }

        if (nmax < 0) return "";
        char d = '0' + nmax;
        return string{d, d, d};
    }
};

auto _ = [](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
