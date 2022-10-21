class Solution {
public:
    int climbStairs(int n) {
        if (n <= 3)
            return n;
        
        int fp = 1, f = 2;
        for (int i = 3; i <= n; ++i) {
            int fn = f + fp;
            fp = f;
            f = fn;
        }
        
        return f;
        
    }
};
