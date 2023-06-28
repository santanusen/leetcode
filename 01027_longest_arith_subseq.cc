class Solution {
public:
    int longestArithSeqLength(vector<int>& nums)
    { 
        int out = 1;
        for(int i = 0; i < 501 / out; ++i)
            for(int d[1001]{}, D[1001]{}; const auto & n: nums)
                out= max({out, d[n + 500] = d[n - i + 500] + 1, D[n] = D[n + i] + 1});
        return out;
    }

    int longestArithSeqLength1(vector<int>& nums) {
        int ans = 0;
        vector<unordered_map<int, int>> dp(nums.size());
        for (int r = 0; r < nums.size(); ++r) {
            for (int l = 0; l < r; ++l) {
                int d = nums[l] - nums[r];
                auto itr = dp[l].find(d);
                dp[r][d] = (itr == dp[l].end() ? 2 : itr->second + 1);
                ans = max(ans, dp[r][d]);
            }
        }

        return ans;
    }

    int longestArithSeqLength2(vector<int>& nums) {
        int seq_max = 1;
        int n = nums.size();
        vector<unordered_map<int, int>> dmap(n);

        for (int i = n - 2; i > -1; --i) {
            for (int j = n - 1; j > i; --j) {
                int d = nums[j] - nums[i];
                auto itr = dmap[j].find(d);
                int l = ((itr == dmap[j].end()) ? 2 : itr->second + 1);
                dmap[i][d] = max(dmap[i][d], l);
                seq_max = max(seq_max, dmap[i][d]);
            }
        }

        return seq_max;
        
    }
};
