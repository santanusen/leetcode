lass Solution {
public:
    bool repeatedSubstringPattern(string s) {
        return (s + s).substr(1, (2 * s.size()) - 2).find(s) != string::npos;
    }

    bool repeatedSubstringPattern2(string s) {
        int n = s.size();
        for (int ns = 2; ns <= n; ++ns) {
            if (n % ns) continue;

            int l = n / ns;
            int i = l;
            for (; i < n; i += l)
                if (s.compare(0, l, s, i, l))
                    break;

            if (i >= n)
                return true;
        }

        return false;
    }
};

auto _ = [](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
