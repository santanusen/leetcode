class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> imap;
        
        for (int i = 0; i < nums.size(); ++i) {
            auto ii = imap.find(target - nums[i]);
            if (ii != imap.end()) {
                return vector<int> {ii->second, i};
            }
            imap[nums[i]] = i;
        }
        return vector<int>();
    }
};
