class Solution {
    public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        vector dp(n + 1, vector<int>(k + 1, 0));
        for (int i = 1; i <= n; ++i) {
            for (int c = 0; c <= k; ++c) { // coins
                int csum = 0;
                int ccmax = min((int)piles[i - 1].size(), c);
                for (int cc = 0; cc <= ccmax; ++cc) {
                    if (cc > 0)
                        csum += piles[i - 1][cc - 1];
                    dp[i][c] = max(dp[i][c], dp[i - 1][c- cc] + csum);
                }
            }
        }

        return dp[n][k];
    }
};

class Solution_DFS {
    struct VectorHasher {
        int operator()(const vector<int> &V) const {
            unsigned int hash = V.size();
            for(auto &i : V) {
                hash ^= i + 0x9e3779b9 + (hash << 6) + (hash >> 2);
            }
            return hash;
        }
    };

    typedef unordered_map<vector<int>, int, VectorHasher> Memo;

    int dfs(vector<vector<int>>& piles, vector<int>& indices, int k, Memo& memo) {
        if (k <= 0) return 0;
        auto itr = memo.find(indices);
        if (itr != memo.end()) return itr->second;
        int maxval = 0;
        for (int i = 0; i < piles.size(); ++i) {
            if (indices[i] < piles[i].size()) {
                int val = piles[i][indices[i]];
                ++indices[i];
                val += dfs(piles, indices, k - 1, memo);
                --indices[i];
                maxval = max(maxval, val);
            }
        }

        memo[indices] = maxval;

        return maxval;
    }

public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        vector indices = vector<int>(piles.size(), 0);
        Memo memo;
        return dfs(piles, indices, k, memo);
    }
};
