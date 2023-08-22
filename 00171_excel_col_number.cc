class Solution {
public:
    int titleToNumber(string columnTitle) {
        int64_t ans = 0;
        for (int64_t i = columnTitle.size() - 1, mult = 1; i > -1; --i, mult *= 26)
            ans += (columnTitle[i] - 'A' + 1) * mult;

        return ans;
    }
};
