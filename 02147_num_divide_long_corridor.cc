class Solution {
public:
    int numberOfWays(string corridor) {
        int M = 1E9 + 7;
        long ans = 1;
        int nc = 0;

        int ps = -1, pe = -1;

        for (int i = 0; i < corridor.size(); ++i) {
            if (corridor[i] == 'S') {
                ++nc;
                if (nc % 2) { // First chair of new group
                    pe = i;
                    if (ps > -1) {
                        ans = (ans * (pe - ps + 1)) % M;
                    }
                } else {
                    ps = i + 1;
                }
            }
        }

        return ((nc < 2 || nc % 2) ? 0 : ans);
        
    }
};

auto _ = [](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
