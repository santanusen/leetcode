class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;

        for (int i = 0; i < l.size(); ++i) {
            if (r[i] - l[i] < 2) {
                ans.push_back(true);
            } else {
                vector<int> sub(nums.begin() + l[i], nums.begin() + r[i] + 1);
                sort(sub.begin(), sub.end());
                int d = sub[1] - sub[0];
                bool arith = true;
                for (int j = 2; j < sub.size(); ++j) {
                    if (sub[j] - sub[j - 1] != d) {
                        arith = false;
                        break;
                    }
                }
                ans.push_back(arith);
            }
        }

        return ans;
        
    }
};

auto _ = [](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
