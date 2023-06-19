class Solution {
    const int IMAX = 30000;

    int dfs(vector<int>& a1, vector<int>& a2, int i, int prev, vector<unordered_map<int, int>>& memo) {
        if (i == a1.size()) return 0;

        auto itr = memo[i].find(prev);
        if (itr != memo[i].end()) return itr->second;

        int cost = IMAX;

        if (a1[i] > prev)
            cost = dfs(a1, a2, i + 1, a1[i], memo);

        auto ub = upper_bound(a2.begin(), a2.end(), prev);

        if (ub != a2.end())
            cost = min(cost, 1 + dfs(a1, a2, i + 1, *ub, memo));

        memo[i][prev] = cost;
        return cost;
    }

public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        //auto itr = unique(arr2.begin(), arr2.end());
        //arr2.resize(distance(arr2.begin(), itr));

        unordered_map<int, int> dp;
        dp[-1] = 0;

        for (auto cur : arr1) {
            unordered_map<int, int> ndp;
            for (auto [prev, nprev] : dp) {
                if (cur > prev) {
                    auto itr = ndp.find(cur);
                    int ncur = (itr == ndp.end() ? INT_MAX : itr->second);
                    ndp[cur] = min(ncur, nprev);
                }

                auto ub = upper_bound(arr2.begin(), arr2.end(), prev);
                if (ub != arr2.end()) {
                    int cur2 = *ub;
                    auto itr = ndp.find(cur2);
                    int ncur2 = (itr == ndp.end() ? INT_MAX : itr->second);
                    ndp[cur2] = min(ncur2, 1 + nprev);
                }
            }

            dp.swap(ndp);
        }

        int ans = INT_MAX;
        for (auto [_, val] : dp)
            ans = min(ans, val);

        return (ans == INT_MAX ? -1 : ans);

    }

    int makeArrayIncreasing_dfs(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        auto itr = unique(arr2.begin(), arr2.end());
        arr2.resize(distance(arr2.begin(), itr));

        vector<unordered_map<int, int>> memo(arr1.size());

        int ans = dfs(arr1, arr2, 0, -1, memo);

        return (ans >= IMAX ? -1 : ans);
    }
};

