class Solution {
public:
    int guessNumber(int n) {
        int m = 1, p, g;
        while (m <= n) {
            p = (m >> 1) + (n >> 1) + (m & n & 1); // p = (m + n) / 2; Avoiding overflow.
            if (!(g = guess(p)))
                return p;
            if (g < 0)
                n = p - 1;
            else
                m = p + 1;
        }
        
        return -1;
        
    }
};

