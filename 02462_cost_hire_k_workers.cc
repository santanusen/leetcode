class Solution {
public:
    Solution() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);}

    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> eligible;
        int i = 0, j = costs.size() - 1;
        for (; i < candidates; ++i)
            eligible.push({costs[i], i});

        int jmin = max((int)costs.size() - candidates, i);
        for (; j >= jmin; --j)
            eligible.push({costs[j], j});


        long long ans = 0;
        for (int kk = 0; kk < k; ++kk) {
            auto [cst, idx] = eligible.top();
            eligible.pop();
            ans += cst;

            if (j >= i) {
                if (idx < i)
                    eligible.push({costs[i], i++});
                else
                    eligible.push({costs[j], j--});
            }
        }

        return ans;
        
    }
};
