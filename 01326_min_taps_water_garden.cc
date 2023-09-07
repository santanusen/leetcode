class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        int m = n + 1;
        int rmax[m];
        memset(rmax, 0, m * sizeof(int));

        for (int i = 0; i < ranges.size(); ++i) {
            int d = ranges[i];
            int b = max(0, i - d), e = min(n, i + d);
            rmax[b] = max(rmax[b], e);
        }

        int ans = 0, r = 0, rn = 0;
        for (int i = 0; i < m; ++i) {
            if (i > rn)
                return -1;

            if (i > r) {
                ++ans;
                r = rn;
            }

            rn = max(rn, rmax[i]);
        }

        return ans;
    }
};

class Solution_Sort {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int, int>> ivals;

        for (int i = 0, d; i < ranges.size(); ++i)
            if ((d = ranges[i]) != 0)
                ivals.push_back({max(i - d, 0), i + d});

        sort(ivals.begin(), ivals.end(),
             [](pair<int, int> &a, pair<int, int>& b)->bool{
                 return a.first < b.first ||
                        a.first == b.first && b.second < a.second;
             });
        
        if (ivals.empty() || ivals[0].first > 0)
            return -1;

        int r = ivals[0].second, rn = r, ans = 1;
        if (rn >= n)
            return 1;

        for (int i = 1; i < ivals.size(); ++i) {
            auto [b, e] = ivals[i];
            if (b <= r) {
                rn = max(rn, e);
                if (rn >= n)
                    return ans + 1;
            } else {
                if (b <= rn) {
                    ++ans;
                    --i;
                    r = rn;
                } else
                    return -1;
            }
        }

        return -1;

    }
};

class Solution_DP {
    const int IMAX = 1E9;
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> dp(n + 1, IMAX);
        dp[0] = 0;

        for (int i = 0; i <= n; ++i) {
            int d = ranges[i];
            int b = max(0, i - d), e = min(n, i + d);
            for (int j = b; j <= e; ++j)
                dp[e] = min(dp[e], dp[j] + 1);
        }

        return (dp[n] < IMAX ? dp[n] : -1);

    }
};

class Solution_Memo {
    const int IMAX = 1E9;

    int dfs(vector<int>& ranges, int n, int r, int pos, vector<int>& dp) {
        if (r >= n + 1)
            return 0;

        if (pos == ranges.size())
            return IMAX;

        if (dp[r] != -1)
            return dp[r];

        int inc = IMAX;
        // Can this tap extend region?
        int d = ranges[pos];
        if (d != 0) {
            int ll = pos - d, rr = pos + d;
            if ((ll <= 0 || ll < r) && rr >= r)
                inc = 1 + dfs(ranges, n, rr + 1, pos + 1 , dp);
        }

        int exc = dfs(ranges, n, r, pos + 1, dp);

        return dp[r] = min(exc, inc);
    }

public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> dp(n + 1, -1);
        int ans = dfs(ranges, n, 0, 0, dp);
        return (ans < IMAX ? ans : -1);
    }
};

auto _ = [](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
