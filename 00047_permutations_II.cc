class Solution {
    vector<vector<int>> res;

    void permute(vector<int>& nums, vector<int>& out, vector<bool>& visited) {
        if (nums.size() == out.size()) {
            res.push_back(out);
            return;
        }

        unordered_set<int> seen;
        for (int i = 0; i < nums.size(); ++i) {
            if (!visited[i] && seen.find(nums[i]) == seen.end()) {
                visited[i] = true;
                seen.insert(nums[i]);
                out.push_back(nums[i]);
                permute(nums, out, visited);
                out.pop_back();
                visited[i] = false;
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> visited(nums.size(), false);
        vector<int> out;
        permute(nums, out, visited);
        return res;
    }
};
