class Solution {
public:
    string largestOddNumber(string num) {
        int i = num.size() - 1;
        while (i > -1 && ((num[i] - '0') % 2 == 0))
            --i;
        return num.substr(0, i + 1);
    }
};

auto _ = [](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
