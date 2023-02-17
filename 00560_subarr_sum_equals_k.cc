class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> psfrq{{0, 1}};
        int ans = 0, ps = 0;
        for (auto n : nums) {
            ps += n;
            /*auto itr = psfrq.find(ps - k);
            if (itr != psfrq.end())
                ans += itr->second;*/
            if (psfrq.count(ps - k))
                ans += psfrq[ps - k];
            ++psfrq[ps]; 
        }

        return ans;
    }
};
