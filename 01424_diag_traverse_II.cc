class Solution {
    void printDiag(vector<vector<int>>& nums, int r, int c, int cmax, vector<int>& ans) {
        while (r > -1 && c < cmax) {
            if (c < nums[r].size())
                ans.push_back(nums[r][c]);
            --r;
            ++c;
        }
    }

public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<pair<int, int>> tbl;
        for (int r = 0; r < nums.size(); ++r)
            for (int c = 0; c < nums[r].size(); ++c)
                tbl.emplace_back(make_pair(r + c, -r));

        sort(tbl.begin(), tbl.end());

        vector<int> ans;
        for (auto [s, mr] : tbl)
            ans.emplace_back(nums[-mr][s + mr]);
        return ans;
    }

    vector<int> findDiagonalOrder2(vector<vector<int>>& nums) {
        int rmax = nums.size(), cmax = 0;
        for (auto& row : nums)
            cmax = max(cmax, (int)row.size());

        vector<int> ans;
        for (int r = 0; r < rmax; ++r)
            printDiag(nums, r, 0, cmax, ans);

        for (int c= 1; c < cmax; ++c)
            printDiag(nums, rmax - 1, c, cmax, ans);

        return ans;
    }
};

auto _ = [](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
