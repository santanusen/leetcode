class Solution {
    void dfs(vector<int>& nums, int pos, int target, vector<int>& combo, vector<vector<int>>& res) {
        if (target == 0) {
            res.push_back(combo);
            return;
        }
        if (pos == nums.size() || target < 0) return;

        for (int i = pos; i < nums.size(); ++i) {
            if(nums[i] > target) break;
            if (i > pos && nums[i] == nums[i - 1]) continue;
            combo.push_back(nums[i]);
            dfs(nums, i + 1, target - nums[i], combo, res);
            combo.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<set<vector<int>>> dp(target + 1);
        for (auto i : candidates) {
            if (i > target) break;
            for (int j = target - i; j >= 0; --j) {
                for (auto v : dp[j]) {
                    v.push_back(i);
                    dp[i + j].insert(v);
                }
            }
            dp[i].insert({i});
        }
        
        return vector<vector<int>>(dp[target].begin(), dp[target].end());
    }

    vector<vector<int>> combinationSum2_dfs(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> combo;
        dfs(candidates, 0, target, combo, res);
        return res;
    }
};
