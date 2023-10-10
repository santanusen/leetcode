class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size(), ans = n;

        set<int> nset(nums.begin(), nums.end());
        nums.clear();
        for (auto num : nset)
            nums.push_back(num);

        for (int i = 0; i < nums.size(); ++i) {
            int l = nums[i], r = l + n - 1;
            int ub = upper_bound(nums.begin(), nums.end(), r) - nums.begin();
            ans = min(ans, n - (ub - i));
        }

        return ans;
        
    }
};
