static const int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        int dp[n + 1];
        dp[n] = 0;
        /*
        for (int i = n - 1; i > -1; --i) {
            int jmax = min(3, n - i);
            int s = stoneValue[i];
            dp[i] = s - dp[i + 1];
            for (int j = 1; j < jmax; ++j) {
                s += stoneValue[i + j];
                dp[i] = max(dp[i], s - dp[i + j + 1]);
            }
        }
        */

        for(int i = n-1; i >= 0; --i) {
            dp[i] = stoneValue[i] - dp[i+1];
            if(i+2 <= n) dp[i] = max(dp[i], stoneValue[i]+stoneValue[i+1]-dp[i+2]);
            if(i+3 <= n) dp[i] = max(dp[i], stoneValue[i]+stoneValue[i+1]+stoneValue[i+2]-dp[i+3]);
        }
        return dp[0] > 0? "Alice": dp[0] == 0? "Tie": "Bob";
        
    }
};
