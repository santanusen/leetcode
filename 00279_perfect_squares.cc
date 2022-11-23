class Solution {
public:
    int numSquares(int n) {
        int DP[n + 1];
        for (int i = 0; i <= n; ++i)
            DP[i] = i;

        for (int i = 2, s; (s = i * i) <= n; ++i)
            for (int j = s; j <= n; ++j)
                DP[j] = min(DP[j], DP[j - s] + 1);
        
        return DP[n];
        
    }
};
