class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> rmap;
        rmap[0] = -1;
        
        int s = 0;
        for (int i = 0; i < nums.size(); ++i) {
            s += nums[i];
            auto itr = rmap.find(s % k);
            if (itr == rmap.end())
                rmap[s % k] = i;
            else if (i - itr->second > 1)
                return true;
        }
        
        return false;
    }
};
