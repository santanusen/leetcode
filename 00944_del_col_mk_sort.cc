class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int C = strs[0].length(), R = strs.size();
        int res = 0;
        for (int i = 0; i < C; ++i) {
            auto nxt = strs[R - 1][i];
            for (int j = R - 2; j > -1; --j) {
                auto c = strs[j][i];
                if (nxt < c) {
                    ++res;
                    break;
                }
                nxt = c;
            }
        }
        return res;
    }
};
