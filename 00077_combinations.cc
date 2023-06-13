class Solution {
    void dfs(uint32_t bmap, int pos, vector<int>& com, int n, vector<vector<int>>& res) {
        if (pos == com.size()) {
            res.push_back(com);
            return;
        }

        for (int i = (pos == 0) ? 0 : com[pos - 1]; i < n; ++i) {
            if ((bmap & (0x1 << i)) == 0) {
                com[pos] = i + 1;
                dfs(bmap | (0x1 << i), pos + 1, com, n, res);
            }
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> com(k);
        dfs(0, 0, com, n, res);

        return res;
    }
};
