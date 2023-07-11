class Solution {
    int ans = INT_MAX;
    void dfs (vector<int>& cookies, int *holdings, int k, int pos, int fair) {
        if (pos == cookies.size()) {
            ans = min(ans, *max_element(holdings, holdings + k));
            return;
        }

        for (int i = 0; i < k; ++i) {
            // Optimization 1:
            // If multiple children have the same holdings, the unfairness
            // will remain the same if we give the current bag to any one
            // of them. Need not repeat the same calculations for each.
            if (i > 0 && holdings[i - 1] == holdings[i]) continue;

            // Optimization 2:
            // If this child is already holding the fair share amount or more
            // giving her the next bag is only going to increase the unfairness.
            if (holdings[i] >= fair) continue;

            holdings[i] += cookies[pos];
            dfs(cookies, holdings, k, pos + 1, fair);
            holdings[i] -= cookies[pos];
        }
    }

public:
    int distributeCookies(vector<int>& cookies, int k) {
        int holdings[8] = {};

        int fair = accumulate(cookies.begin(),cookies.end(),0) / k;

        // Optimization 3:
        // Sort the cookie bags in descending order so that we
        // hit optimization 2 earlier.
        sort(cookies.begin(), cookies.end(), greater<int>());

        dfs(cookies, holdings, k, 0, fair);
        return ans;
    }
};

// Optimization 4:
// Get rid of all the io overheads.
auto _ = []() {ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); return false;}();
