class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int maxs0 = INT_MIN, maxs1 = INT_MIN;
        int mins0 = INT_MAX, mins1 = INT_MAX;
        for (auto n : nums) {
            if (n > maxs1 && (maxs1 = n) > maxs0)
                swap(maxs0, maxs1);
            if (n < mins1 && (mins1 = n) < mins0)
                swap(mins0, mins1);            
        }
        return (maxs0 * maxs1) - (mins0 * mins1);
    }

    int maxProductDifference2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return (nums[nums.size() - 1] * nums[nums.size() - 2]) -
               (nums[0] * nums[1]);
    }
};

auto _ = [](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
