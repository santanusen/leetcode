auto fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
    long long getCost(vector<int>& nums, vector<int>& cost, int base) {
        long long ans = 0;
        for (int i = 0; i < nums.size(); ++i)
            ans += (long long) abs(nums[i] - base) * cost[i];
        return ans;
    }

public:

    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long ans = getCost(nums, cost, nums[0]);

        int l = *min_element(nums.begin(), nums.end());
        int r = *max_element(nums.begin(), nums.end());

        while (l < r) {
            int m = (l + r) / 2;
            auto c1 = getCost(nums, cost, m);
            auto c2 = getCost(nums, cost, m + 1);
            ans = min(c1, c2);
            if (c1 > c2)
                l = m + 1;
            else
                r = m;
        }

        return ans;
    }

    long long minCost1(vector<int>& nums, vector<int>& cost) {
        vector<pair<int, int>> ncp;
        for (int i = 0; i < nums.size(); ++i)
            ncp.push_back({nums[i], cost[i]});

        sort(ncp.begin(), ncp.end());

        vector<long long> csumv;
        long long csum = 0;
        for (auto [_, c] : ncp)
            csumv.push_back(csum = csum + c);

        long long tcost = 0;
        for (int i = 1; i < ncp.size(); ++i)
            tcost += ((long long) ncp[i].second * (ncp[i].first - ncp[0].first));

        long long ans = tcost;
        for (int i = 1; i < ncp.size(); ++i) {
            long long gap = ncp[i].first - ncp[i - 1].first;
            tcost += gap * csumv[i - 1];
            tcost -= gap * (csum - csumv[i - 1]);
            ans = min(ans, tcost);
        }

        return ans;
    }

    long long minCost2(vector<int>& nums, vector<int>& cost) {
        vector<pair<int, int>> ncp;
        for (int i = 0; i < nums.size(); ++i)
            ncp.push_back({nums[i], cost[i]});

        sort(ncp.begin(), ncp.end());

        long long ncsum = 0, csum = 0;
        vector<long long> ncsumv, csumv;
        for (auto [n, c] : ncp) {
            ncsumv.push_back(ncsum = ncsum + (long long)n * c);
            csumv.push_back(csum = csum + c);
        }

        long long ans = LLONG_MAX;

        for (int i = 0; i < ncp.size(); ++i) {
            long long cst = 0;
            if (i > 0)
                cst += (csumv[i - 1] * ncp[i].first - ncsumv[i - 1]);
            cst += (ncsum - ncsumv[i] - (csum - csumv[i]) * ncp[i].first);

            ans = min(ans, cst);
            if (ans == 0) break;
        }

        return ans;
    }

};
