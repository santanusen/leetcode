class Solution {
    int ans, vmax;

    int dfs(vector<int>& nums, int k, int pos, vector<int>& memo) {
        if (pos >= (int)(nums.size()))
            return 0;

        if (pos > 0 && memo[pos] != INT_MIN)
            return memo[pos];

        int smax = 0;
        for (int i = 1; i <= k; ++i) {
            smax = max(dfs(nums, k, pos + i, memo), smax);
        }

        if (pos > -1) {
            smax += nums[pos];
            vmax = max(vmax, nums[pos]);
            memo[pos] = smax;
        }

        ans = max(smax, ans);

        return smax;
    }

public:
    int constrainedSubsetSum_DP(vector<int>& nums, int k) {
        ans = INT_MIN;
        vmax = INT_MIN;
        vector<int> memo(nums.size(), INT_MIN);
        dfs(nums, k, -1, memo);
        return (vmax < 0 ? vmax : ans);  
    }

    int constrainedSubsetSum_heap(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;
        pq.push({nums[0], 0});
        int ans = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            while (i - pq.top().second > k)
                pq.pop();

            int csum = max(0, pq.top().first) + nums[i];
            pq.push({csum, i});
            ans = max(ans, csum);
        }

        return ans;
    }    

    int constrainedSubsetSum(vector<int>& nums, int k) {
        deque<int> dq;
        int dp[nums.size()];
        int ans = INT_MIN;

        for (int i = 0; i < nums.size(); ++i) {
            if (!dq.empty() && i - dq.front() > k)
                dq.pop_front();

            dp[i] = (!dq.empty() ? dp[dq.front()] : 0) + nums[i];
            ans = max(ans, dp[i]);

            while (!dq.empty() && dp[dq.back()] < dp[i])
                dq.pop_back();

            if (dp[i] > 0)
                dq.push_back(i);
        }

        return ans;

    }
};

auto _ = [](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
