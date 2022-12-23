class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // States
        enum { BUYABLE, HOLDING, COOLING, NSTATES };
        
        // DP:
        // Buyable: Not holding any stock, cooled off.
        // Holding: Holding some stock after buying.
        // Cooling: Just sold. Cooling off to become buyable again.
        vector<vector<int>> DP (NSTATES, vector<int>(prices.size(), 0));

        // Base cases:
        DP[BUYABLE][0] = 0; // Have not made any transactions yet.
        DP[HOLDING][0] = -prices[0]; // Bought at today's price.
        DP[COOLING][0] = INT_MIN; // Don't have anything to sell.

        for (int i = 1; i < prices.size(); ++i) {
            // Buyable:
            // Possible transitions from:
            //    Buyable: Did nothing
            //    Cooling: Did nothing
            DP[BUYABLE][i] = max(DP[BUYABLE][i - 1], DP[COOLING][i - 1]);

            // Holding:
            // Possible transitions from:
            //    Buyable: Bought today
            //    Holding: Did nothing
            DP[HOLDING][i] = max(DP[BUYABLE][i - 1] - prices[i], DP[HOLDING][i - 1]);

            // Cooling:
            // Possible transitions from:
            //    Holding: Sold today
            DP[COOLING][i] = DP[HOLDING][i - 1] + prices[i];
        }

        return max(DP[BUYABLE][prices.size() - 1],
                   max(DP[HOLDING][prices.size() -1], DP[COOLING][prices.size() - 1]));
        
    }
};
