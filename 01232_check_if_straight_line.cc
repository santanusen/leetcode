static const int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
    typedef long long Int;
public:
    bool checkStraightLine(vector<vector<int>>& coord) {
        if (coord.size() < 3) return true;
        Int x = coord[0][0], y = coord[0][1];
        Int dx = x - coord[1][0], dy = y - coord[1][1];

        for (int i = 2; i < coord.size(); ++i)
            if (dx * (y - coord[i][1]) != dy * (x - coord[i][0]))
                return false;

        return true;
    }
};
