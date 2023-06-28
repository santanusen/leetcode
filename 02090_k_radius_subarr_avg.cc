auto fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<int> avgs(nums.size(), -1);
        int w = k + k + 1, n = nums.size();
        if (n < w) return avgs;

        long long sum = 0;
        for (int i = 0; i < w - 1; ++i)
            sum += nums[i];

        for (int l = 0, m = k, r = w - 1; r < n; ++l, ++m, ++r) {
            sum += nums[r];
            avgs[m] = sum / w;
            sum -= nums[l];
        }

        return avgs;
        
    }
};
