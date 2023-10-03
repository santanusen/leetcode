class Solution {
public:
    int candy(vector<int>& ratings) {
        const int n = ratings.size();

        int ld[n];
        ld[0] = 0;
        for (int i = 1; i < n; ++i)
            ld[i] = ((ratings[i] > ratings[i - 1]) ? 1 + ld[i - 1] : 0);

        int rd[n];
        rd[n - 1] = 0;
        int ans = max(ld[n - 1], rd[n - 1]) + 1;
        for (int i = n - 2; i > -1; --i) {
            rd[i] = ((ratings[i] > ratings[i + 1]) ? 1 + rd[i + 1] : 0);
            ans += (max(ld[i], rd[i]) + 1);
        }

        return ans;
    }

#if 0
    int candy_sort(vector<int>& ratings) {
        const int n = ratings.size();
        vector<int> rtx;
        for (int i = 0; i < n; ++i)
            rtx.push_back(i);
        sort(rtx.begin(), rtx.end(), [&](int a, int b)->bool{return ratings[a] < ratings[b];});

        vector<int> candies(n, 0);
        int ans = 0;
        for (auto i : rtx) {
            int cnd = 1, r = ratings[i];
            if (i > 0 && r > ratings[i - 1])
                cnd = max(cnd, candies[i - 1] + 1);

            if (i + 1 < n && r > ratings[i + 1])
                cnd = max(cnd, candies[i + 1] + 1);

            candies[i] = cnd;
            ans += cnd;
        }

        return ans; 
    }
#endif
};

auto _ = [](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
