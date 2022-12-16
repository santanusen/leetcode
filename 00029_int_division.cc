class Solution {
public:
    int divide(int dividend, int divisor) {
        // Some base cases.
        if (divisor == 1) return dividend;
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;

        // Determine sign.
        bool neg = ((dividend < 0) != (divisor < 0));

        // Convert to positive numerator and denominator.
        // Negation of INT_MIN does not fit in int. Keep the max
        // that fits into the int, i.e. INT_MAX and store the
        // rest in carry.
        int n = ((dividend == INT_MIN) ? INT_MAX : abs(dividend));
        int d = ((divisor == INT_MIN) ? INT_MAX : abs(divisor));
 
        // If int n or c was not sufficient to hold the abs() value
        // save the leftover in carry.
        int nc = ((dividend == INT_MIN) ? 1 : 0);
        int dc = ((divisor == INT_MIN) ? 1: 0);
        if (d > n || (d == n && dc > nc)) return 0;

        // Quotient and remainder.
        int q = 0, r = 0;

        int N = sizeof(int) * 8; // Number of bits in int.

        // High-school math style division - in binary
        // d     n      q
        // 11 ) 1101 ( 100
        //      11
        //      ___
        //       00  <-- r
        //       00
        //       ___
        //        01 <-- r
        //        00
        //        ___
        //         1 <-- r

        for (int i = N - 1; i > -1; --i) {
            r <<= 1;
            if (n & (1 << i)) r |= 1;
            if (r >= d) {
                r -=d;
                q |= (1 << i);
            }
        }

        if (nc) q += divide(r + nc, d); // Take care of carry, if any.

        return ((neg) ? -q : q);
    }
};
