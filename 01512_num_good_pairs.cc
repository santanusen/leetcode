class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int frq[101] = {0}, ans = 0;
        for (auto n : nums) ans += frq[n]++;
        return ans;
    }
};
auto _ = [](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
