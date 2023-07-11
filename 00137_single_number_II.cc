class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int s1 = 0, s2 = 0;
        for(auto n: nums)
            s1 = (~s2) & (s1 ^ n), s2 = (~s1) & (s2 ^ n);
        return s1;
    }

    int singleNumber1(vector<int>& nums) {
        int ans = 0;

        for (int i = 0; i < 32; ++i) {
            int sum = 0;
            for (const int num : nums)
                sum += num >> i & 1;
            sum %= 3;
            ans |= sum << i;
        }

        return ans;
    }

    int singleNumber2(vector<int>& nums) {
        int bfreq[32] = {0};
        for (uint32_t n : nums)
            for (int i = 0; i < 32; ++i)
                if (n & (1 << i))
                    ++bfreq[i];

        uint32_t ans = 0;
        for (int i = 0; i < 32; ++i)
            if (bfreq[i] % 3)
                ans |= (1 << i);

        return ans;
        
    }
};
