class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); ++i)
            nums[i] += nums[i - 1];

        vector<int> res;
        for (auto q : queries) {
            int l = 0, r = nums.size() - 1;
            while (l <= r) {
                int m = (l + r) >> 1;
                if (nums[m] == q) {
                    l = m + 1;
                    break;
                }
                if (nums[m] < q) l = m + 1;
                else r = m - 1;
            }
            res.push_back(l);
        }
        return res;
        
    }
};
