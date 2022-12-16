class Solution {
    vector<vector<int>> res;

    void permute(vector<int>& nums, vector<int>& out, vector<bool>& seen) {
        if (nums.size() == out.size()) {
            res.push_back(out);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (!seen[i]) {
                seen[i] = true;
                out.push_back(nums[i]);
                permute(nums, out, seen);
                out.pop_back();
                seen[i] = false;
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> seen(nums.size(), false);
        vector<int> out;
        permute(nums, out, seen);
        return res;
    }
};
