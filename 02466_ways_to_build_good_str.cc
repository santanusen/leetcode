static const int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        int M = 1E9 + 7;
        vector<int> dp(high + 1, 0);
        dp[0] = 1;
        int ans = 0;
        for (int i = 0; i <= high; ++i) {
            if (i + zero <= high)
                dp[i + zero] = (dp[i + zero] + dp[i]) % M;
            if (i + one <= high)
                dp[i + one] = (dp[i + one] + dp[i]) % M;
            /*
            if (i >= low)
                ans = (ans + dp[i]) % M;
            */
        }


        for (int i = low; i <= high; ++i)
            ans = (ans + dp[i]) % M;

        return ans;
        
    }
};
