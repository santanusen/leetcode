class Solution {
public:
    int countOrders(int n) {
        int M = 1e9 + 7;
        int64_t ans = 1;
        for (int i = 1; i < n; ++i) {
            int slots = 2 * i + 1;
            int perms = (slots * (slots + 1)) / 2;
            ans = ((ans % M) * perms) % M; 
        }

        return ans;
        
    }
};
