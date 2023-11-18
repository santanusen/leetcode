class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        long cur = 0;
        int l = 0;

        for (int r = 0; r < nums.size(); ++r) {
            long tgt = nums[r];
            cur += tgt;

            while ((r - l + 1) * tgt - cur > k) {
                cur -= nums[l];
                ++l;
            }

            ans = max(ans, r - l + 1);
        }

        //return nums.size() - l;
        return ans;
    }

    int maxFrequency2(vector<int>& nums, int k) {
        map<int, int> freq;
        for (auto num : nums)
            ++freq[num];

        int ans = 0;
        for (auto itr = freq.begin(); itr != freq.end(); ++itr) {
            auto ileft = itr;
            if (ileft != freq.begin()) --ileft; else ileft = freq.end();

            int ff = itr->second, kk = k;
            while (kk > 0 && ileft != freq.end()) {
                int ldist = itr->first - ileft->first;
                if (ldist > kk) {
                    kk = 0;
                } else {
                    int cmax = min(ileft->second, kk / ldist);
                    ff += cmax;
                    kk -= (cmax * ldist); 
                        
                    if (ileft != freq.begin()) --ileft; else ileft = freq.end();
                }
            }

            ans = max(ans, ff);
        }
        
        return ans;
    }
};

auto _ = [](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
