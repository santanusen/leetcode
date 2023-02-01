class Solution {
public:
    int tribonacci(int n) {
        const int bonacci = 3; // Tri-bonacci.
        int dp[bonacci] = {0, 1};
        for (int i = 2, sum = 1; i < bonacci; sum += dp[i], ++i)
            dp[i] = sum;

        if (n < bonacci) return dp[n];

        while (n-- >= bonacci) {
            int s = accumulate(dp, dp + bonacci, 0);
            for (int i = 0; i + 1 < bonacci; ++i)
                dp[i] = dp[i + 1];
            dp[bonacci - 1] = s;
        }

        return dp[bonacci - 1];  
    }
};
