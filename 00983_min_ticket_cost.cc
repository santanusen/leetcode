class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int dp[366];
        dp[0] = 0;

        int i = 1;
        for (int d = 0; i < 366; ++i) {
            if (i == days[d]) {
                dp[i] = min({dp[i - 1] + costs[0],
                             dp[max(i - 7, 0)] + costs[1],
                             dp[max(i - 30, 0)] + costs[2]});
                if (++d == days.size())
                    break;
            } else
                dp[i] = dp[i - 1];
        }

        return dp[i];   
    }
};
