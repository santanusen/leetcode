class Solution {
public:

    int maxProfit2(vector<int>& prices) {
        int mprice = INT_MIN, mprofit = 0;
        
        for (int i = prices.size() -1; i > -1; --i) {
            mprice = max(prices[i], mprice);
            mprofit = max(mprice - prices[i], mprofit);
        }
        
        return mprofit;
        
    }
    
    int maxProfit(vector<int>& prices) {
        int mprice = INT_MAX, mprofit = 0;
        
        for (auto p : prices) {
            mprice = min(p, mprice);
            mprofit = max(p - mprice, mprofit);
        }
        
        return mprofit;
        
    }
};
