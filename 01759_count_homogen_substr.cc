class Solution {
public:
    int countHomogenous(string s) {
        int M = 1E9 + 7;
        int ans = 0, l = 0;
        char prev = '\0';
        for (auto c : s) {
            if (c == prev)
                ++l;
            else {
                l = 1;
                prev = c;
            }

            ans = (ans + l) % M;
        }

        return ans;
        
    }
};

auto _ = [](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
