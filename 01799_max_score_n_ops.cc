static const int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
    int dfs(vector<int>& nums, int mask, int npairs, vector<int>& memo) {
        if (2 * npairs == nums.size()) return 0;
        if (memo[mask] != -1) return memo[mask];

        int smax = 0;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                if (((mask >> i) & 1) == 1 || ((mask >> j) & 1) == 1) continue;
                int nxtMask = mask | (1 << i) | (1 << j);
                int score = (npairs + 1) * __gcd(nums[i], nums[j]) +
                            dfs(nums, nxtMask, npairs + 1, memo);
                smax = max(smax, score);
            }
        }
        return (memo[mask] = smax);

    }

public:
    int maxScore(vector<int>& nums) {
        //vector<int> memo((1 << nums.size()), -1);
        //return dfs(nums, 0, 0, memo);

        int nstates = 1 << nums.size();
        int dp[nstates];
        dp[nstates - 1] = 0;

        for (int mask = nstates - 2; mask > -1; --mask) {
            int nbitset = __builtin_popcount(mask);
            if (nbitset & 0x1) continue; // Odd num bits set.
            int npairs = nbitset >> 1;
            
            dp[mask] = 0;
            for (int i = 0; i < nums.size() - 1; ++i) {
                if (((mask >> i) & 1) == 1) continue;
                for (int j = i + 1; j < nums.size(); ++j) {
                    if (((mask >> j) & 1) == 1) continue;
                    int nxtMask = mask | (1 << i) | (1 << j);
                    int score = (npairs + 1) * __gcd(nums[i], nums[j]) + dp[nxtMask];
                    dp[mask] = max(dp[mask], score);
                }
            }
        }

        return dp[0];
    }
};

class Solution_wrong {
public:
    int maxScore(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, set<pair<int, int>>> gmap;
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int g = gcd(nums[i], nums[j]);
                gmap[i].insert({g, j});
                gmap[j].insert({g, i});
            }
        }

        int ans = 0;
        for (int i = n / 2; i > 0; --i) {
            int gmax = 0, a, b;
            for (auto& gg : gmap) {
                auto glast = gg.second.rbegin();
                if (glast != gg.second.rend() && glast->first > gmax) {
                    gmax = glast->first;
                    a = gg.first;
                    b = glast->second;
                }
            }
            ans += (i * gmax);
            // Clean up
            for (auto& gp : gmap[a])
                gmap[gp.second].erase({gp.first, a});
            for (auto& gp : gmap[b])
                gmap[gp.second].erase({gp.first, b});
            gmap.erase(a);
            gmap.erase(b);
        }

        return ans;
        
    }
};
