class Solution {
public:
    int numberOfMatches(int n) {
        /*
        int np2 = 1;
        while (np2 < n)
            np2 <<= 1;
        return np2 - (np2 - n) - 1;
        */
        return n - 1;
    }
};
