static const int __ = []() { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; }();

class Solution {    
    int dfs(vector<int>& prices, int fee, int day, int buyday, vector<vector<int>>& dp) {
        if (day >= prices.size()) {
            if (buyday == -1) return 0;
            else return (0 - prices[buyday]);
        }

        if (dp[day][buyday + 1] != INT_MIN) return dp[day][buyday + 1];

        int phold = dfs(prices, fee, day + 1, buyday, dp);
        int pbuy = INT_MIN;
        int ptransact = (buyday == -1) ?
                        dfs(prices, fee, day + 1, day, dp) :
                        dfs(prices, fee, day + 1, -1, dp) + prices[day] - prices[buyday] - fee;

        return dp[day][buyday + 1] = max(phold, ptransact);
    }

public:
    int maxProfit(vector<int>& prices, int fee) {
        int free = 0;
        int hold = -prices[0];

        for (int i = 1; i < prices.size(); ++i) {
            int f = max(free, hold + prices[i] - fee);
            hold = max(hold, free - prices[i]);
            free = f;
        }

        return free;
    }

    int maxProfit2(vector<int>& prices, int fee) {
        //vector<vector<int>> dp(prices.size(), vector<int>(prices.size() + 1, INT_MIN));
        //return dfs(prices, fee, 0, -1, dp);

        int n = prices.size();
        int free[n], hold[n];
        free[0] = 0;
        hold[0] = -prices[0];

        for (int i = 1; i < n; ++i) {
            free[i] = max(free[i - 1], hold[i - 1] + prices[i] - fee);
            hold[i] = max(hold[i - 1], free[i - 1] - prices[i]);
        }

        return free[n - 1];
    }
};
