class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> psfrq(k, 0);
        psfrq[0] = 1;
        int ans = 0, ps = 0;
        for (auto n : nums) {
            //if (n < 0) n = k + (n % k);
            ps = (ps + k + n % k) % k;
            ans += psfrq[ps]++; 
        }

        return ans;   
    }
};
