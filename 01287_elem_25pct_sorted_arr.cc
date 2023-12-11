class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int c = 0, n = arr.size(), p = -1;
        for (auto v : arr) {
            if (v != p) {
                p = v;
                c = 1;
            } else {
                ++c;
            }
            if ((c << 2) > n)
                return v;
        }

        return -1;
    }
};

auto _ = [](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
