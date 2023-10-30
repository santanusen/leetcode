class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(),
                [](int a, int b)->bool {
                    int ba = __builtin_popcount(a), bb = __builtin_popcount(b);
                    return ba < bb || ba == bb && a < b; 
                });
        return arr;
    }
};

auto _ = [](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
