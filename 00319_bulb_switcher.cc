class Solution {
    int sqrt_floor(int n) {
        int l = 0, r = n;
        while (l <= r) {
            long long int m = (l + r) / 2;
            long long int m2 = m * m;
            if (m2 == n) return m;
            if (m2 > n) r = m - 1;
            else l = m + 1;
        }
        return r;
    }

public:
    int bulbSwitch(int n) {
        //return sqrt_floor(n);
        return sqrt(n);
    }
};
