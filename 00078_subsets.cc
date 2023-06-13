class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        res.push_back({});

        int l = 0;
        while (res[res.size() - 1].size() < nums.size()) {
            int r = res.size() - 1;
            for (int i = l; i <= r; ++i) {
                for (auto num : nums)
                    if (res[i].empty() || res[i][res[i].size() - 1] < num) {
                        auto v = res[i];
                        v.push_back(num);
                        res.push_back(v);
                    }
            }
            l = r + 1;
        }

        return res;
        
    }
};
