class Solution {
public:
    int hammingWeight(uint32_t n) {
#if 0
        //return __builtin_popcount(n);
        int ans;
        for (ans = 0; n; n &= (n - 1))
            ++ans;
        return ans;
#endif
        int ans;
        for (ans = 0; n; n >>= 1)
            ans += (n & 0x1);
        return ans;     
    }
};
