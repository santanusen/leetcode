class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans {0};

        for (int i = 1, j = 0, k = ans.size(); i <= n; ++i) {
            ans.push_back(1 + ans[j]);
            if (++j == k) {
                k = ans.size();
                j = 0;
            }
        }

        return ans;
    }
};
