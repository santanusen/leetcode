class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();

        int aggr = accumulate(nums.begin(), nums.end(), 0);

        for (int i = 0, pref = 0; i < n; ++i) {
            int v = nums[i];
            int d =  (i > 0 ? d = (v * i) - pref : 0);
            pref += v;
            if (i < n - 1)
                d += ((aggr - pref) - (n - 1 - i) * v);

            nums[i] = d;
        }

        return nums;       
    }
};

auto _ = [](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
