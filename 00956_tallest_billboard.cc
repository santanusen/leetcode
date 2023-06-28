class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        int sum = 0;
        sort(rods.begin(), rods.end());
        for(int i = 0; i < rods.size(); i++) {
            sum += rods[i];
        }

        int dp[sum + 1];
        dp[0] = 0;
        for (int i = 1; i< = sum; i++) {
            dp[i] = -1;
        }

        for (int rod : rods) {
            int dpCopy[sum + 1];
            copy(dp, dp + (sum + 1), dpCopy);

            for (int i = 0; i <= sum - rod; i++) {
                if (dpCopy[i] < 0) continue;

                dp[i + rod] = max(dp[i + rod], dpCopy[i]);
                dp[abs(i - rod)] = max(dp[abs(i - rod)], dpCopy[i] + min(i, rod));
            }
        }

        return dp[0];
    }
};

class Solution2 {
public:
    int tallestBillboard(vector<int>& rods) {
        unordered_map<int, int> dp;
        dp[0] = 0;

        for (auto r : rods) {
            unordered_map<int, int> ndp(dp);
            for (auto [diff, taller] : dp) {
                int shorter = taller - diff;

                // Add r to taller
                int ndiff = diff + r;
                auto itr = ndp.find(ndiff);
                int extaller = (itr == ndp.end() ? 0 : itr->second);
                ndp[ndiff] = max(taller + r, extaller);

                // Add r to shorter
                int taller2 = max(shorter + r, taller);
                int ndiff2 = abs(shorter + r - taller);
                auto itr2 = ndp.find(ndiff2);
                int extaller2 = (itr2 == ndp.end() ? 0 : itr2->second);
                ndp[ndiff2] = max(taller2, extaller2);
            }

            dp = ndp;
        }

        // Return max height with 0 diff.
        return dp[0];
    }
};

class Solution_TLE {
    static inline uint64_t pack_pair(int l, int r) {
        return (uint64_t(l) << 32 | uint64_t(r));
    }

    typedef vector<unordered_map<uint64_t, int>> memo_t;

    int dfs(vector<int>& rods, int pos, int l, int r, memo_t& memo) {
        if (pos == rods.size())
            return (l == r ? l : 0);

        uint64_t idx = pack_pair(l, r);
        auto itr = memo[pos].find(idx);
        if (itr != memo[pos].end()) return itr->second;

        return memo[pos][idx] = max({
            dfs(rods, pos + 1, l, r, memo),
            dfs(rods, pos + 1, l + rods[pos], r, memo),
            dfs(rods, pos + 1, l, r + rods[pos], memo)
        });
    }

public:
    int tallestBillboard(vector<int>& rods) {
        memo_t memo(rods.size());
        return dfs(rods, 0, 0, 0, memo);
    }
};
