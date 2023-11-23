class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end(), greater<int>());
        int imax = piles.size() / 3 * 2;
        int ans = 0;
        for (int i = 1; i < imax; i += 2)
            ans += piles[i];
        return ans;
    }
};

auto _ = [](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
