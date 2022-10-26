class Solution {
public:
    int minPartitions(string n) {
        int res = 0;
        for (const auto c : n) {
            res = max(res, int(c - '0'));
            if (res == 9) break;
        }
        return res;
    }
};
