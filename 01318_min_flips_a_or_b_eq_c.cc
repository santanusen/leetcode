class Solution {
public:
    int minFlips2(int a, int b, int c) {
        int flips = 0;
        while (a || b || c) {
            int aa = a & 1, bb = b & 1, cc = c & 1;
            if ((aa | bb) != cc) {
                if (cc == 1)
                    ++flips;
                else {
                    if (aa) ++flips;
                    if (bb) ++flips;
                }
            }
            a >>= 1;
            b >>= 1;
            c >>= 1;
        }

        return flips;
        
    }

    int minFlips(int a, int b, int c) {
        return
        __builtin_popcount((a | b) ^ c) +
        __builtin_popcount(a & b & ~c);
    }
};
