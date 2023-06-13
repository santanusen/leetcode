class Solution {
public:
    
   long long int test(int a, int index, int n)
    {
        long long int b = max(0, a - index);
        long long int res = (a + b) * (a - b + 1) / 2;
        b = max(0, (a - ((n - 1) - index)));
        res = res + (a + b) * (a - b + 1) / 2;
        return res - a;
    }
    
    int maxValue(int n, int index, int maxSum) {
        maxSum -= n;
        int l = 0, r = maxSum;
        
        while(l < r) {
            int m= (l + r + 1) / 2;
            if (test(m, index, n) > maxSum)
                r = m - 1;
            else
                l = m;
        }

        return l + 1;
    }
};

class Solution2 {
    typedef long long INT;
    static inline INT area_trp(INT h, INT l) {
        return (2 * h - l + 1) * l / 2;
    }

    static int extra(int start, int inc, int smax) {
        INT b = start * 2 / inc - 1;
        INT c = 2 * smax / inc;
        INT d = sqrt(b * b + 4 * c);
        return (d - b) / 2;
    }
public:
    int maxValue(int n, int index, int maxSum) {
        maxSum -= n;
        int l = index + 1, r = n - index;
        auto [sml, lrg] = minmax(l, r);
        const INT A = area_trp(lrg, lrg) + area_trp(lrg, sml) - lrg;
        if (maxSum >= A)
            return lrg + (maxSum - A) / n + 1;
        const INT B = area_trp(sml, sml) * 2 - sml;
        if (maxSum >= B)
            return sml + extra(sml * 2, 1, maxSum - B) + 1;
        return extra(1, 2, maxSum) + 1;
        
    }
};
