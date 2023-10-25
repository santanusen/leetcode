class Solution {
public:
    int kthGrammar(int n, int k) {
        int i = 1, v = 0;
        for (int l = 1; l < n; ++l) {
            int mult = (0x1 << (n - l - 1));
            int lmax = ((i << 1) - 1) * mult;
            if (k <= lmax) { // Left Subtree
                i = ((i << 1) - 1);
            } else { // Right Subtree
                i = (i << 1);
                v = 1 - v;
            }
        }
        return v;      
    }
};

/*

1:                1
2:         1               2
3:     1       2       3       4
4:   1   2   3   4   5   6   7   8
5:  1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6
*/
