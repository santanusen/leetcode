class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int c1 = 0, flips = 0;
        for (auto c : s)
            if (c == '1') ++c1;
            else flips = min(flips + 1, c1);

        return flips;
    }

    int minFlipsMonoIncr2(string s) {
        int c0 = count(s.begin(), s.end(), '0');
        int c1 = 0, flips = s.size() - c0;

        for (auto c : s) {
            if (c == '0')
                --c0;
            else {
                flips = min(flips, c0 + c1);
                ++c1;
            }
        }

        return flips;
        
    }
};
