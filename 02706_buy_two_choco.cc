class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int c1 = INT_MAX, c2 = INT_MAX;
        for (auto p : prices)
            if (p < c2 && (c2 = p) < c1)
                swap(c1, c2);
        return (money - c1 - c2 >= 0 ? money - c1 - c2 : money);
    }
};
auto _ = [](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
