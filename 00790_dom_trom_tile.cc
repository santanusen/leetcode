class Solution {
public:
    int numTilings(int n) {
        if (n < 3) return n;
        unsigned int DP[n + 1];
        DP[0] = 1;
        DP[1] = 1; // |
        DP[2] = 2; // ||, =
        DP[3] = 5;

        const int MOD = 1E9 + 7;
        for (int i = 4; i <= n; ++i)
            DP[i] = (2 * DP[i - 1] + DP[i - 3]) % MOD;

        return DP[n];
        
    }
};
