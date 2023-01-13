class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        for (int i = 0, cost = 0; i < costs.size(); ++i)
            if ((cost += costs[i]) > coins) return i;
        return costs.size();
    }
};
