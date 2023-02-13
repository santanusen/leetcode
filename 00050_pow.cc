class Solution {
    double pow_impl(double x, long long int n) {
        if (n == 0) return 1.0;
        vector<double> tbl {1.0, x};
        for (long long int i = 2; i <= n; i <<=1)
            tbl.push_back(tbl.back() * tbl.back());

        double res = 1.0;
        for (int i = 1; n ; ++i, n >>= 1)
            if (n & 0x1)
                res *= tbl[i];
        return res;
    }

public:
    double myPow(double x, int n) {
        long long int nn = n;
        if (nn < 0) {
            x = 1.0 / x;
            nn = -nn;
        }

        return pow_impl(x, nn);
    }
};
