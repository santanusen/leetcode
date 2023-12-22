class Solution {
public:
    int maxScore(string s) {
        int score = 0, ones = 0, smax = INT_MIN;
        int n = s.size();

        for (int i = 0; i < n - 1; ++i) {
            char c = s[i];
            if (c == '0')
                ++score;
            else {
                --score;
                ++ones;
            }
            smax = max(smax, score);
        }

        if (s[n - 1] == '1')
            ++ones;

        return smax + ones;
        
    }
};
